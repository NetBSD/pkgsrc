# $NetBSD: Makefile,v 1.5 2003/06/02 01:19:58 jschauma Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.3
CATEGORIES=		emulators
MASTER_SITES=		http://www.glue.umd.edu/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.glue.umd.edu/~jasonp/
COMMENT=		IA64 simulator (Intel(R) Architecture 64)

USE_GMAKE=		yes
DIST_SUBDIR=		${PKGNAME}

MAKEFILE=		makefile.unx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim

.include "../../mk/bsd.pkg.mk"
