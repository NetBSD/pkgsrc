# $NetBSD: options.mk,v 1.3 2011/04/29 11:48:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opendkim
PKG_SUPPORTED_OPTIONS=	filter debug dkim-stats vbr
PKG_SUGGESTED_OPTIONS=	filter

.include "../../mk/bsd.options.mk"

###
### Debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

###
### Install filter (milter) plugin
###
.if !empty(PKG_OPTIONS:Mfilter)
EGDIR=		${PREFIX}/share/examples/opendkim
RCD_SCRIPTS=	opendkim

CONFIGURE_ARGS+=	--enable-filter
CONFIGURE_ARGS+=	--with-milter=${PREFIX}
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	opendkim/Makefile.in
SUBST_SED.conf+=	-e 's|@EGDIR@|${EGDIR}|g'

#CONF_FILES=		${EGDIR}/opendkim.conf.sample \
#			${PKG_SYSCONFDIR}/opendkim.conf

PLIST_SRC+=		${PKGDIR}/PLIST.filter
.else
CONFIGURE_ARGS+=	--disable-filter
.endif

###
### Build with VBR support
###
.if !empty(PKG_OPTIONS:Mvbr)
CONFIGURE_ARGS+=	--enable-vbr
PLIST_SRC+=		${PKGDIR}/PLIST.vbr
.else
CONFIGURE_ARGS+=	--disable-vbr
.endif

###
### Install stats which outputs opendkim statistics
###
.if !empty(PKG_OPTIONS:Mdkim-stats)
#.include "../../mk/db1.builtin.mk"
CONFIGURE_ARGS+=	--enable-stats
PLIST_SRC+=		${PKGDIR}/PLIST.stats
.else
CONFIGURE_ARGS+=	--disable-stats
.endif
