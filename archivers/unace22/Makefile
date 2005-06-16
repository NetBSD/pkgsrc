# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:37 jlam Exp $
#

DISTNAME=	linunace22
PKGNAME=	unace22-2.20
CATEGORIES=	archivers
MASTER_SITES=	http://ace.imptech.net/ \
		http://www.shedz.com/winace/ \
		http://www.maxeline.com/winace/ \
		http://hem.passagen.se/vanlid/winace/ \
		http://w1.314.telia.com/~u31412016/dload/ \
		http://www.winace.mewa.net/mirror/ \
		http://ace.imptech.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives (2.2 linux binary)

ONLY_FOR_PLATFORM=	NetBSD-1.5Z[A-Z]-i386 NetBSD-1.6*-i386 \
			NetBSD-[2-9]*-i386 Linux-*-i[3-6]86

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin/unace22

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
