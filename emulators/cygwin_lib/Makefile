# $NetBSD: Makefile,v 1.12 2020/01/26 17:31:09 rillig Exp $
#

DISTNAME=		cygwin-1.5.13-1
PKGNAME=		${DISTNAME:S/-/!/:S/-/./g:S/!/_lib-/}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_CYGWIN:=release/cygwin/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		interix-pkg-people@NetBSD.org
HOMEPAGE=		https://www.cygwin.com/
COMMENT=		Basic Cygwin library and executables for emulation

ONLY_FOR_PLATFORM=	Interix-*-*

DIST_SUBDIR=		cygwin
WRKSRC=			${WRKDIR}

SYMLINKS=		cygpath ipcrm ipcs kill mount ps regtool umount
INSTALLATION_DIRS=	bin emul/cygwin/bin

do-build: # nothing

do-install:
	${INSTALL_LIB} ${WRKSRC}/usr/bin/cygwin1.dll ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/emul/cygwin \
		${DESTDIR}${PREFIX}/emul/cygwin/bin
	@for f in ${WRKSRC}/usr/bin/*.exe; do \
		${INSTALL_LIB} $$f \
		${DESTDIR}${PREFIX}/emul/cygwin/bin/$$(basename $${f%.exe}); \
	done
.for f in ${SYMLINKS}
	${LN} -sf ../emul/cygwin/bin/${f} ${DESTDIR}${PREFIX}/bin/cygwin-${f}
.endfor

.include "../../mk/bsd.pkg.mk"
