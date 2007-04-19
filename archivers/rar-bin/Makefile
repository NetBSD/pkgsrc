# $NetBSD: Makefile,v 1.6 2007/04/19 15:30:22 xtraeme Exp $
#

DISTNAME=		rarlinux-3.6.0
PKGNAME=		${DISTNAME:C/linux/-bin/}
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarsoft.com/rar/ \
			ftp://ftp.rarsoft.com/rar/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/rar_archiver.htm
COMMENT=		RAR command line archiver (Linux binary)

LICENSE=		rar-license

ONLY_FOR_PLATFORM=	*-*-i386
WRKSRC=			${WRKDIR}/rar

# old name of the package
CONFLICTS=		rarlinux-[0-9]* rar-linux-[0-9]*

SUSE_COMPAT32=		yes

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar_static ${PREFIX}/bin/rar-bin
#	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar-bin
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rar-bin
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/rar-bin
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/share/doc/rar-bin

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
