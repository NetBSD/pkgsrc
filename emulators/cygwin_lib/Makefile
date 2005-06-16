# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		cygwin-1.5.13-1
PKGNAME=		${DISTNAME:S/-/!/:S/-/./g:S/!/_lib-/}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_CYGWIN:=release/cygwin/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.cygwin.com/
COMMENT=		Basic Cygwin library and executables for emulation

ONLY_FOR_PLATFORM=	Interix-*-*

DIST_SUBDIR=		cygwin
WRKSRC=			${WRKDIR}

SYMLINKS=		cygpath ipcrm ipcs kill mount ps regtool umount
INSTALLATION_DIRS=	bin emul/cygwin/bin

do-build: # nothing

do-install:
	${INSTALL_LIB} ${WRKSRC}/usr/bin/cygwin1.dll ${PREFIX}/bin/
	${INSTALL_PROGRAM_DIR} ${PREFIX}/emul/cygwin ${PREFIX}/emul/cygwin/bin
	@for f in ${WRKSRC}/usr/bin/*.exe; do \
		${INSTALL_LIB} $$f ${PREFIX}/emul/cygwin/bin/$$(basename $${f%.exe}); \
	done
.for f in ${SYMLINKS}
	${LN} -sf ../emul/cygwin/bin/${f} ${PREFIX}/bin/cygwin-${f}
.endfor

.include "../../mk/bsd.pkg.mk"
