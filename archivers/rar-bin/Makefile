# $NetBSD: Makefile,v 1.7 2007/07/29 05:18:36 jlam Exp $

DISTNAME=		rarlinux-3.6.0
PKGNAME=		${DISTNAME:C/linux/-bin/}
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarsoft.com/rar/ \
			ftp://ftp.rarsoft.com/rar/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/rar_archiver.htm
COMMENT=		RAR command line archiver (Linux binary)

CONFLICTS=		rarlinux-[0-9]* rar-linux-[0-9]*

LICENSE=		rar-license

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat

WRKSRC=			${WRKDIR}/rar
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar_static ${PREFIX}/bin/rar-bin
#	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar-bin
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rar-bin
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/rar-bin
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/share/doc/rar-bin

.include "../../mk/bsd.pkg.mk"
