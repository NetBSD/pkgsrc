# $NetBSD: options.mk,v 1.2 2008/02/21 21:17:45 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi
PKG_SUPPORTED_OPTIONS=	# empty

.include "../../mk/bsd.prefs.mk"

NVI_NON_WIDE_PLATFORMS=	NetBSD-[0-3].*-*	# missing swprintf()
.for _pattern_ in ${NVI_NON_WIDE_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
NVI_NON_WIDE_PLATFORM=	yes
.  endif
.endfor

# Only support the ``wide-curses'' option on platforms that have the
# necessary wide character support.
#
.if !defined(NVI_NON_WIDE_PLATFORM)
PKG_SUPPORTED_OPTIONS+=	wide-curses
PKG_LEGACY_OPTS+=	ncursesw:wide-curses
.endif

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-widechar
.else
.  include "../../mk/curses.buildlink3.mk"
.endif
