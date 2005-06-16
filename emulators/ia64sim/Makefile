# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:50 jlam Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.3
CATEGORIES=		emulators
MASTER_SITES=		http://www.glue.umd.edu/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.glue.umd.edu/~jasonp/
COMMENT=		IA64 simulator (Intel(R) Architecture 64)

USE_TOOLS+=		gmake
DIST_SUBDIR=		${PKGNAME}

MAKEFILE=		makefile.unx
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
