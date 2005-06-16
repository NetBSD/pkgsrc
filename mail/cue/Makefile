# $NetBSD: Makefile,v 1.47 2005/06/16 06:58:02 jlam Exp $

DISTNAME=	cue-snap-20050131
PKGNAME=	cue-20050131
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	mh-e like mail user agent

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cue
PKG_SUPPORTED_OPTIONS=	canna idea inet6
PKG_OPTIONS_LEGACY_VARS+=	CUE_USE_CANNA:canna

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

INSTALLATION_DIRS=	bin

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc ${PREFIX}/share/examples/cue
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp  ${PREFIX}/share/doc/cue

.include "../../mk/bsd.pkg.mk"
