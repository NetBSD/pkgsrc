# $NetBSD: Makefile,v 1.44 2005/03/23 09:42:33 jlam Exp $

DISTNAME=	cue-snap-20050131
PKGNAME=	cue-20050131
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	mh-e like mail user agent

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

# Global & legacy options
.if defined(CUE_USE_CANNA) && !empty(CUE_USE_CANNA:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	canna
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.cue
PKG_SUPPORTED_OPTIONS=	canna idea inet6
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6) && (${OPSYS} != "SunOS")
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna=${BUILDLINK_PREFIX.canna}
.else
CONFIGURE_ARGS+=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Midea)
CONFIGURE_ARGS+=	--enable-idea
.endif

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc ${PREFIX}/share/examples/cue
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp  ${PREFIX}/share/doc/cue

.include "../../mk/bsd.pkg.mk"
