# $NetBSD: Makefile,v 1.2 2001/02/17 09:07:00 agc Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@netbsd.org
HOMEPAGE=		http://caml.inria.fr/distrib-caml-light-eng.html
COMMENT=		Another implementation of Caml

ALL_TARGET=		world

WRKSRC=			${WRKDIR}/cl74/src

do-configure:
	(cd ${WRKSRC}; make configure)

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
