# $NetBSD: Makefile,v 1.4 2001/02/20 11:33:52 wiz Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.3
CATEGORIES=		emulators
MASTER_SITES=		http://www.glue.umd.edu/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.glue.umd.edu/~jasonp/
COMMENT=		IA64 simulator (Intel(R) Architecture 64)

USE_GMAKE=		yes
DIST_SUBDIR=		${PKGNAME}

MAKEFILE=		makefile.unx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
