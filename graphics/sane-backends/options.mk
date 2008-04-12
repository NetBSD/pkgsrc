# $NetBSD: options.mk,v 1.6 2008/04/12 22:43:02 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sane-backends
PKG_SUPPORTED_OPTIONS=		inet6 sane-backends-hp3900
PKG_SUGGESTED_OPTIONS=		#defined

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif


###
### hp3900 support
###
PLIST_VARS+=	hp3900

.if !empty(PKG_OPTIONS:Mhp3900)
PLIST.hp3900=	yes
DISTFILES+=	hp3900-sane1017_src_0.5.tar.gz
SITES.hp3900-sane1017_src_0.5.tar.gz=${MASTER_SITE_SOURCEFORGE:=hp3900-series/}
post-patch:
	cd ${WRKSRC} && \
	${PATCH} -p1 <${WRKDIR}/hp3900-sane1017_src_0.5/hp3900-sane1017_0.5.diff
.endif
