# $NetBSD: Makefile,v 1.28 2003/11/12 03:39:40 jschauma Exp $

DISTNAME=	cue-snap-20031027
PKGNAME=	cue-20031027
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	mh-e like mail user agent

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6 USE_IDEA CUE_USE_CANNA

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(CUE_USE_CANNA) && !empty(CUE_USE_CANNA:M[Yy][Ee][Ss])
.include "../../inputmethod/canna-lib/buildlink2.mk"
CONFIGURE_ARGS+=	--with-canna=${BUILDLINK_PREFIX.canna}
.else
CONFIGURE_ARGS+=	--without-canna
.endif
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.if defined(USE_IDEA)
CONFIGURE_ARGS+=	--enable-idea
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc ${PREFIX}/share/examples/cue
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp  ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.html ${PREFIX}/share/doc/cue

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
