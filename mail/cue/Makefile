# $NetBSD: Makefile,v 1.9 2002/04/05 23:44:40 wiz Exp $

DISTNAME=	cue-snap-20010917
PKGNAME=	cue-20010917
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	packages@netbsd.org
COMMENT=	mh-e like mail user agent

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	yes
USE_SSL=	yes
.if exists(/usr/include/openssl/rsa.h)
CONFIGURE_ARGS+=--with-openssl=/usr
.else
CONFIGURE_ARGS+=--with-openssl=${LOCALBASE}
.endif
.if ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
# require Canna, for now, cue assumes Japanese encoding anyways
DEPENDS+=	Canna-lib>=3.5.2:../../japanese/canna-lib
CONFIGURE_ARGS+=--with-canna=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc ${PREFIX}/share/examples/cue
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp  ${PREFIX}/share/doc/cue
	${INSTALL_DATA} ${WRKSRC}/cue.html ${PREFIX}/share/doc/cue

.include "../../mk/bsd.pkg.mk"
