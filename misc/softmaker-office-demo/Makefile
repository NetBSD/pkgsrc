# $NetBSD: Makefile,v 1.1.1.1 2007/09/07 20:58:19 wiz Exp $
#

DISTNAME=	ofl06trial
PKGNAME=	softmaker-office-demo-2006
CATEGORIES=	misc
MASTER_SITES=	http://www.softmaker.net/down/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.softmaker.net/
COMMENT=	SoftMaker Office (TextMaker and PlanMaker) demo version (Linux binary)

WRKSRC=		${WRKDIR}/officetrial
USE_LANGUAGES=	# none
EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base x11

INSTALLATION_DIRS=	bin lib/softmaker

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/textmaker
	${ECHO} 'cd ${PREFIX}/lib/softmaker' >> ${WRKDIR}/textmaker
	${ECHO} './textmaker' >> ${WRKDIR}/textmaker
	${ECHO} '#!/bin/sh' > ${WRKDIR}/planmaker
	${ECHO} 'cd ${PREFIX}/lib/softmaker' >> ${WRKDIR}/planmaker
	${ECHO} './planmaker' >> ${WRKDIR}/planmaker

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/textmaker ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/planmaker ${PREFIX}/bin
	cd ${WRKSRC} && pax -rwpp * ${PREFIX}/lib/softmaker

.include "../../mk/bsd.pkg.mk"
