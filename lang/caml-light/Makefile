# $NetBSD: Makefile,v 1.6 2004/12/03 15:15:00 wiz Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://caml.inria.fr/distrib-caml-light-eng.html
COMMENT=		Another implementation of Caml

WRKSRC=			${WRKDIR}/cl74/src
BUILD_TARGET=		world

do-configure:
	(cd ${WRKSRC}; make configure)

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
