# $NetBSD: options.mk,v 1.6 2020/11/13 14:06:48 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.psi

#PKG_SUPPORTED_OPTIONS+=	aspell hunspell enchant whiteboard xscreensaver
#PKG_SUGGESTED_OPTIONS+=	aspell hunspell enchant

PKG_SUPPORTED_OPTIONS+=	aspell hunspell whiteboard xscreensaver
PKG_SUGGESTED_OPTIONS+=	aspell hunspell

# from an idea stolen from ../../misc/openoffice3.
PSI_SUPPORTED_LANGUAGES=	be cs de eo es es-es fr it ja mk pl pt-br ru \
				sl sv uk ur-pk vi zh-cn zh-tw

.for l in ${PSI_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=	lang-${l}
PLIST_VARS+=		${l}
.endfor

.include "../../mk/bsd.options.mk"

# handle the languages first
#   bit of special logic, as the dialects of languages are handled
#   as lang_DIALECT (aka, lower underscore UPPER) in the PSI translations
.for lang in ${PKG_OPTIONS:Mlang-*:S/lang-//g}
PLIST.${lang} =		yes
.  if ${lang:M??-??}
    LANG_FILES+=	psi_${lang:C/-.*//g}_${lang:C/.*-//g:tu}.qm
.  else
    LANG_FILES+=	psi_${lang}.qm
.  endif
.endfor

# enable aspell
.if !empty(PKG_OPTIONS:Maspell)
CONFIGURE_ARGS+=	--with-aspell-inc=${BUILDLINK_PREFIX.aspell}/include
CONFIGURE_ARGS+=	--with-aspell-lib=${BUILDLINK_PREFIX.aspell}/lib
.include "../../textproc/aspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-aspell
.endif

# enable enchant
.if !empty(PKG_OPTIONS:Menchant)
.include "../../textproc/enchant2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-enchant
.endif

# enable hunspell
.if !empty(PKG_OPTIONS:Mhunspell)
CONFIGURE_ARGS+=	--with-hunspell-inc=${BUILDLINK_PREFIX.hunspell}/include
CONFIGURE_ARGS+=	--with-hunspell-lib=${BUILDLINK_PREFIX.hunspell}/lib
.include "../../textproc/hunspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-hunspell
.endif

# enable whiteboarding
.if !empty(PKG_OPTIONS:Mwhiteboard)
CONFIGURE_ARGS+=	--enable-whiteboarding
.endif

# enable xscreensaver extension
.if empty(PKG_OPTIONS:Mxscreensaver)
CONFIGURE_ARGS+=	--disable-xss
.endif

# enable growl
# .if empty(PKG_OPTIONS:Mgrowl)
# CONFIGURE_ARGS+=	--with-growl=${BUILDLINK_PREFIX.growl}
# .else
# CONFIGURE_ARGS+=	--disable-growl
# .endif
