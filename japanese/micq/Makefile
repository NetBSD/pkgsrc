# $NetBSD: Makefile,v 1.3 2000/02/06 01:08:29 wiz Exp $

DISTNAME=	micq-0.4.3
PKGNAME=	ja-${DISTNAME}
CATEGORIES=	japanese net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.4.3/ \
		http://www.freebsd.org/~flathill/distfiles/ \
		http://micq.maesoft.net/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.freebsd.org/~flathill/distfiles/
PATCHFILES=	micq-0.4.3-jp.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	eric@fox.phoenix.az.us
HOMEPAGE=	http://micq.maesoft.net/

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin/jmicq
		${MKDIR} ${PREFIX}/share/doc/ja-micq
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja-micq

.include "../../mk/bsd.pkg.mk"
