# $NetBSD: Makefile,v 1.1.1.1 1999/12/10 12:59:02 agc Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.glue.umd.edu/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.glue.umd.edu/~jasonp

BUILD_DEPENDS+=		unzip:../../archivers/unzip

USE_GMAKE=		yes

MAKEFILE=		makefile.unx

do-extract:
	${MKDIR} ${WRKDIR}; cd ${WRKDIR} && unzip -uLa ${_DISTDIR}/${_DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
