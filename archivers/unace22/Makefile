# $NetBSD: Makefile,v 1.5 2003/04/25 18:29:22 jmmv Exp $
#

DISTNAME=	linunace22
PKGNAME=	unace22-2.20
WRKSRC=		${WRKDIR}
CATEGORIES=	archivers
MASTER_SITES=	http://www.servidas.net/winace/ \
		http://www.maxeline.com/winace/ \
		http://www.winace.mewa.net/mirror/ \
		http://hem.passagen.se/vanlid/winace/ \
		http://ace.imptech.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives (2.2 linux binary)

ONLY_FOR_PLATFORM= NetBSD-1.5Z[A-Z]-i386 NetBSD-1.[6-9]*-i386 Linux-*-i[3-6]86

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin/unace22

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
