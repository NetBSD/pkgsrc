# $NetBSD: Makefile,v 1.1 2025/07/05 12:12:13 hauke Exp $

DISTNAME=	asl-current-142-bld290
PKGNAME=	asl-1.42.290
CATEGORIES=	devel
MASTER_SITES=	http://john.ccac.rwth-aachen.de:8000/ftp/as/source/c_version/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://john.ccac.rwth-aachen.de:8000/as
COMMENT=	Portable macro cross assembler for a variety of microprocessors
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/asl-current

USE_LANGUAGES=	c

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	bin lib include/asl ${PKGMANDIR}/man1

pre-configure:
	${CP} ${FILESDIR}/Makefile.def.pkgsrc ${WRKSRC}/Makefile.def
	mkdir ${WRKSRC}/objects

.include "../../mk/bsd.pkg.mk"
