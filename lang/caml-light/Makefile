# $NetBSD: Makefile,v 1.8 2007/01/18 20:44:25 rillig Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://caml.inria.fr/caml-light/index.en.html
COMMENT=		Another implementation of Caml

WRKSRC=			${WRKDIR}/cl74/src
BUILD_TARGET=		world
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && make configure

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
