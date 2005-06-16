# $NetBSD: Makefile,v 1.13 2005/06/16 06:57:46 jlam Exp $
#

VERS=		0.51b3
DISTNAME=	elfsh-${VERS}-portable
PKGNAME=	elfsh-${VERS}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://elfsh.segfault.net/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://elfsh.segfault.net/
COMMENT=	ELF format exploration shell

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_GNU_READLINE=	yes

SUBST_STAGE.elfsh=	post-patch
SUBST_FILES.elfsh=	vm/include/elfsh.h
SUBST_SED.elfsh=	-e s,@@SH@@,${SH}, -e s,@@PREFIX@@,${PREFIX},
SUBST_CLASSES+=		elfsh

# XXX This package should be converted to use libtool

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vm/elfsh ${PREFIX}/bin/elfsh
	${INSTALL_DATA} ${WRKSRC}/libelfsh/libelfsh.a ${PREFIX}/lib/libelfsh.a
	${INSTALL_DATA} ${WRKSRC}/libelfsh/libelfsh.so ${PREFIX}/lib/libelfsh.so
	${INSTALL_DATA} ${WRKSRC}/libelfsh/include/libelfsh.h ${PREFIX}/include/libelfsh.h
	${INSTALL_DATA_DIR} ${PREFIX}/lib/elfsh
	${INSTALL_DATA} ${WRKSRC}/modules/modremap.so ${PREFIX}/lib/elfsh
	${INSTALL_DATA} ${WRKSRC}/modules/modtest.so ${PREFIX}/lib/elfsh
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/elfsh
	${INSTALL_DATA} ${WRKSRC}/doc/elfsh-ref.txt ${PREFIX}/share/doc/elfsh/elfsh-ref.txt
	${INSTALL_DATA} ${WRKSRC}/doc/libelfsh-ref.txt ${PREFIX}/share/doc/elfsh/libelfsh-ref.txt

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
