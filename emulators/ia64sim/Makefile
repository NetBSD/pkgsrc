# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:35 jlam Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.3
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.glue.umd.edu/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.glue.umd.edu/~jasonp/
COMMENT=		IA64 simulator (Intel(R) Architecture 64)

USE_TOOLS+=		gmake
DIST_SUBDIR=		${PKGNAME_NOREV}

MAKEFILE=		makefile.unx
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${PREFIX}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
