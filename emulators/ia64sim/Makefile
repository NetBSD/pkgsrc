# $NetBSD: Makefile,v 1.3 2001/02/17 18:38:18 wiz Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.glue.umd.edu/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.glue.umd.edu/~jasonp/
COMMENT=		IA64 simulator (Intel(R) Architecture 64)

BUILD_DEPENDS+=		unzip:../../archivers/unzip

USE_GMAKE=		yes

MAKEFILE=		makefile.unx

do-extract:
	${MKDIR} ${WRKDIR}; cd ${WRKDIR} && unzip -uLa ${_DISTDIR}/${_DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
