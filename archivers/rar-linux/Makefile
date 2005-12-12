# $NetBSD: Makefile,v 1.13 2005/12/12 14:43:23 joerg Exp $
#

DISTNAME=		rarlinux-3.5.1
PKGNAME=		${DISTNAME:C/linux/-linux/}
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarsoft.com/rar/ \
			ftp://ftp.rarsoft.com/rar/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/rar/
COMMENT=		RAR command line archiver (Linux binary)

LICENSE=		rar-license

ONLY_FOR_PLATFORM=	*-*-i386
WRKSRC=			${WRKDIR}/rar

# old name of the package
CONFLICTS=		rarlinux-[0-9]*

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar_static ${PREFIX}/bin/rar-linux
#	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar-linux
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rar-linux
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/rar-linux
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/share/doc/rar-linux

.include "../../mk/bsd.pkg.mk"
