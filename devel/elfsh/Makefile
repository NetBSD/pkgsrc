# $NetBSD: Makefile,v 1.2 2003/05/12 21:27:10 jmc Exp $
#

VERS=		0.43b
DISTNAME=	${PKGNAME}-portable
PKGNAME=	elfsh-${VERS}
CATEGORIES=	devel
MASTER_SITES=	http://www.hert.org/projects/elfsh/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.hert.org/projects/elfsh/
COMMENT=	ELF format exploration shell

WRKSRC=		${WRKDIR}/elfsh_0.43

USE_BUILDLINK2=	yes

# XXX This package should be converted to use libtool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elfsh/elfsh ${PREFIX}/bin/elfsh
	${INSTALL_DATA} ${WRKSRC}/libelfsh/libelfsh.a ${PREFIX}/lib/libelfsh.a
	${INSTALL_DATA} ${WRKSRC}/libelfsh/libelfsh.so ${PREFIX}/lib/libelfsh.so
	${INSTALL_DATA} ${WRKSRC}/libelfsh/include/libelfsh.h ${PREFIX}/include/libelfsh.h
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/elfsh
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/elfsh/README
	${INSTALL_DATA} ${WRKSRC}/doc/libelfsh-ref.txt ${PREFIX}/share/doc/elfsh/libelfsh-ref.txt

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
