# $NetBSD: Makefile,v 1.15 2002/10/25 12:13:18 wiz Exp $

DISTNAME=	cue-snap-20020826
PKGNAME=	cue-20020826
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	packages@netbsd.org
COMMENT=	mh-e like mail user agent

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6 USE_IDEA

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# require Canna, for now, cue assumes Japanese encoding anyways
CONFIGURE_ARGS+=	--with-canna=${BUILDLINK_PREFIX.canna-lib}
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

.include "../../inputmethod/canna-lib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
