# $NetBSD: Makefile,v 1.1.1.1 2000/06/21 11:42:46 bouyer Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@netbsd.org
HOMEPAGE=		http://caml.inria.fr/distrib-caml-light-eng.html

ALL_TARGET=		world

WRKSRC=			${WRKDIR}/cl74/src

do-configure:
	(cd ${WRKSRC}; make configure)

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
