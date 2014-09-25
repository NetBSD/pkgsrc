# $NetBSD: options.mk,v 1.5 2014/09/25 13:56:50 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opendkim
PKG_SUPPORTED_OPTIONS=	opendkim-filter debug dkim-stats vbr
PKG_SUGGESTED_OPTIONS=	opendkim-filter

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
.if !empty(PKG_OPTIONS:Mopendkim-filter)
EGDIR=		${PREFIX}/share/examples/opendkim
RCD_SCRIPTS=	opendkim

CONFIGURE_ARGS+=	--enable-filter
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}

CONF_FILES=		${EGDIR}/opendkim.conf.sample \
			${PKG_SYSCONFDIR}/opendkim.conf

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample \
				${DESTDIR}${EGDIR}/opendkim.conf.sample

PLIST_SRC+=		${PKGDIR}/PLIST.filter
.else
CONFIGURE_ARGS+=	--disable-filter
.endif


###
### Build with VBR support
###
.if !empty(PKG_OPTIONS:Mvbr)
CONFIGURE_ARGS+=	--enable-vbr
PKGCONFIG_OVERRIDE+=	libvbr/vbr.pc.in
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
REPLACE_PERL+=		stats/opendkim-expire.in
REPLACE_PERL+=		stats/opendkim-gengraphs.in
REPLACE_PERL+=		stats/opendkim-genstats.in
.else
CONFIGURE_ARGS+=	--disable-stats
.endif
