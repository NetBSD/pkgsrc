# $NetBSD: Makefile,v 1.54 2008/01/18 05:08:21 tnn Exp $

DISTNAME=	cue-snap-20061225
PKGNAME=	${DISTNAME:S/snap-//}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	mh-e like mail user agent

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER} == "ido"
CPPFLAGS+=	-DNO_ATTRIBUTE
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

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
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
