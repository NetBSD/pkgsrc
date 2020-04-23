# $NetBSD: Makefile,v 1.14 2020/04/23 19:42:41 rillig Exp $
#

DISTNAME=	atasm106
PKGNAME=	atasm-1.06
PKGREVISION=	1
CATEGORIES=	devel cross emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atasm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/atasm/
COMMENT=	Cross-assembler for 6502 optimized to code for Atari 8 bit computers
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_CONFIGURE=	YES
BUILD_DIRS=	src
MAKE_ENV=	ZLIB="-L${BUILDLINK_PREFIX.zlib}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib -lz"

DOCDIR=		${PREFIX}/share/doc/atasm
EXAMPLE_DIR=	${PREFIX}/share/examples/atasm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR} ${EXAMPLE_DIR}

SUBST_CLASSES+=		docdir
SUBST_FILES.docdir=	src/atasm.1.in
SUBST_STAGE.docdir=	pre-install
SUBST_SED.docdir=	-e 's,%%DOCDIR%%,${DOCDIR},g'
SUBST_MESSAGE.docdir=	Edit DOCDIR variable

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/atasm        ${DESTDIR}${PREFIX}/bin/atasm
	${MV}              ${WRKSRC}/src/atasm.1.in ${WRKSRC}/src/atasm.1
	${INSTALL_DATA}    ${WRKSRC}/src/atasm.1      ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA}    ${WRKSRC}/docs/atasm.pdf   ${DESTDIR}${DOCDIR}
	${INSTALL_DATA}    ${WRKSRC}/docs/atasm.blurb ${DESTDIR}${DOCDIR}
.for i in iomac.lib sample.m65 sysequ.m65 test.m65
	${INSTALL_DATA}    ${WRKSRC}/examples/${i}    ${DESTDIR}${EXAMPLE_DIR}/
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
