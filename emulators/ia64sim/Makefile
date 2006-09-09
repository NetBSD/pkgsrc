# $NetBSD: Makefile,v 1.14 2006/09/09 02:41:59 obache Exp $

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

MAKE_FILE=		makefile.unx
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${PREFIX}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
