# $NetBSD: Makefile,v 1.1.1.1 2004/02/27 15:10:29 wiz Exp $
#

DISTNAME=		rarlinux-3.3.0
CATEGORIES=		archivers
MASTER_SITES=		http://www.rarsoft.com/rar/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/rar/
COMMENT=		RAR command line archiver (Linux binary)

WRKSRC=			${WRKDIR}/rar
USE_BUILDLINK2=		yes

ONLY_FOR_PLATFORM= NetBSD-1.5Z[A-Z]-i386 NetBSD-1.[6-9]*-i386 Linux-*-i[3-6]86

WRKSRC=		${WRKDIR}/rar

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar-linux
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar-linux
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rar-linux
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/rar-linux
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/share/doc/rar-linux

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
