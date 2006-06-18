# $NetBSD: Makefile,v 1.16 2006/06/18 00:56:11 rillig Exp $
#

VERS=		0.51b3
DISTNAME=	elfsh-${VERS}-portable
PKGNAME=	elfsh-${VERS}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://elfsh.segfault.net/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://elfsh.segfault.net/
COMMENT=	ELF format exploration shell

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_GNU_READLINE=	yes

SUBST_CLASSES+=		elfsh
SUBST_STAGE.elfsh=	post-patch
SUBST_MESSAGE.elfsh=	Filling placeholders.
SUBST_FILES.elfsh=	vm/include/elfsh.h
SUBST_SED.elfsh=	-e s,@@SH@@,${SH},
SUBST_SED.elfsh+=	-e s,@@PREFIX@@,${PREFIX},

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
