# $NetBSD: Makefile,v 1.3 2005/12/27 09:58:56 dillo Exp $

DISTNAME=	estd-netbsd-r4
PKGNAME=	estd-0.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.elektro-eel.org/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.elektro-eel.org/
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep-enabled CPUs

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-i386 NetBSD-[3-9]*-i386

WRKSRC=			${WRKDIR}/estd-r4

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_MESSAGE.prefix=	Substituting PREFIX.
SUBST_FILES.prefix=	*.sh
SUBST_SED.prefix=	-e 's|@PREFIX@|${PREFIX}|'
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		estd

.include "../../mk/bsd.pkg.mk"
