# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:24 jmmv Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
WRKSRC=			${WRKDIR}/cl74/src
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@netbsd.org
HOMEPAGE=		http://caml.inria.fr/distrib-caml-light-eng.html
COMMENT=		Another implementation of Caml

ALL_TARGET=		world

do-configure:
	(cd ${WRKSRC}; make configure)

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
