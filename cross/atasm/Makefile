# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:17 tv Exp $
#

DISTNAME=	atasm104
PKGNAME=        atasm-1.04
PKGREVISION=	1
CATEGORIES=	devel cross emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atasm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/atasm/
COMMENT=	Cross-assembler for 6502 optimized to code for Atari 8 bit computers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=         ${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=   YES
USE_BUILDLINK3=	YES

DOCDIR=		${PREFIX}/share/doc/atasm

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/atasm ${PREFIX}/bin/atasm
	${SED} -e 's,%%DOCDIR%%,${DOCDIR},g' < ${WRKSRC}/atasm.1.in > ${WRKSRC}/atasm.1
	${INSTALL_DATA} ${WRKSRC}/atasm.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/atasm.txt ${DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
