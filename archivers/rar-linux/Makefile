# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:37 jlam Exp $
#

DISTNAME=		rarlinux-3.4.1
PKGNAME=		${DISTNAME:C/linux/-linux/}
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarsoft.com/rar/ \
			ftp://ftp.rarsoft.com/rar/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/rar/
COMMENT=		RAR command line archiver (Linux binary)

LICENSE=		rar-license

ONLY_FOR_PLATFORM=	NetBSD-1.5Z[A-Z]-i386 NetBSD-1.6*-i386 \
			NetBSD-[2-9]*-i386 Linux-*-i[3-6]86
WRKSRC=			${WRKDIR}/rar

# old name of the package
CONFLICTS=		rarlinux-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
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

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
