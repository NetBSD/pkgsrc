# $NetBSD: Makefile,v 1.12 2011/11/01 11:39:59 bsiegert Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://caml.inria.fr/caml-light/index.en.html
COMMENT=		Another implementation of Caml

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/cl74/src
BUILD_TARGET=		world
INSTALLATION_DIRS+=	bin lib/caml-light ${PKGMANDIR}/man1

USE_TOOLS+=		pax

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "MirBSD"
CPP=			/usr/libexec/cpp -P -C -Dunix
.endif

do-configure:
	cd ${WRKSRC} && ${MAKE} configure

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
