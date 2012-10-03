# $NetBSD: Makefile,v 1.9 2012/10/03 00:10:28 asau Exp $
#

DISTNAME=	atasm104
PKGNAME=	atasm-1.04
PKGREVISION=	2
CATEGORIES=	devel cross emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atasm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/atasm/
COMMENT=	Cross-assembler for 6502 optimized to code for Atari 8 bit computers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/atasm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atasm ${DESTDIR}${PREFIX}/bin/atasm
	${SED} -e 's,%%DOCDIR%%,${DOCDIR},g' < ${WRKSRC}/atasm.1.in > ${WRKSRC}/atasm.1
	${INSTALL_DATA} ${WRKSRC}/atasm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/atasm.txt ${DESTDIR}${DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
