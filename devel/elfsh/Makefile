# $NetBSD: Makefile,v 1.24 2016/03/09 21:40:05 tnn Exp $
#

VERS=		0.51b3
DISTNAME=	elfsh-${VERS}-portable
PKGNAME=	elfsh-${VERS}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://elfsh.asgardlabs.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://elfsh.segfault.net/
COMMENT=	ELF format exploration shell

MAKE_JOBS_SAFE=		no

LDFLAGS+=	${BUILDLINK_LDADD.dl:Q}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		elfsh
SUBST_STAGE.elfsh=	post-patch
SUBST_MESSAGE.elfsh=	Fixing hardcoded paths.
SUBST_FILES.elfsh=	vm/include/elfsh.h
SUBST_SED.elfsh=	-e '/ELFSH_SHELL/s,/bin/bash,${SH},'
SUBST_SED.elfsh+=	-e '/ELFSH_MODPATH/s,/usr/share/,${PREFIX}/lib/,'

# XXX This package should be converted to use libtool

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vm/elfsh ${DESTDIR}${PREFIX}/bin/elfsh
	${INSTALL_DATA} ${WRKSRC}/libelfsh/libelfsh.a \
		${DESTDIR}${PREFIX}/lib/libelfsh.a
	${INSTALL_DATA} ${WRKSRC}/libelfsh/libelfsh.so \
		${DESTDIR}${PREFIX}/lib/libelfsh.so
	${INSTALL_DATA} ${WRKSRC}/libelfsh/include/libelfsh.h \
		${DESTDIR}${PREFIX}/include/libelfsh.h
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/elfsh
	${INSTALL_DATA} ${WRKSRC}/modules/modremap.so \
		${DESTDIR}${PREFIX}/lib/elfsh
	${INSTALL_DATA} ${WRKSRC}/modules/modtest.so \
		${DESTDIR}${PREFIX}/lib/elfsh
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/elfsh
	${INSTALL_DATA} ${WRKSRC}/doc/elfsh-ref.txt \
		${DESTDIR}${PREFIX}/share/doc/elfsh/elfsh-ref.txt
	${INSTALL_DATA} ${WRKSRC}/doc/libelfsh-ref.txt \
		${DESTDIR}${PREFIX}/share/doc/elfsh/libelfsh-ref.txt

.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
