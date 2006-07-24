# $NetBSD: Makefile,v 1.5 2006/07/24 08:11:38 adam Exp $

DISTNAME=	estd-r5
PKGNAME=	estd-0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.elektro-eel.org/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.elektro-eel.org/
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep-enabled CPUs

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-i386 NetBSD-[3-9]*-i386 DragonFly-*-i386

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_MESSAGE.prefix=	Substituting PREFIX.
SUBST_FILES.prefix=	*.sh
SUBST_SED.prefix=	-e 's|@PREFIX@|${PREFIX}|'
RCD_SCRIPTS=		estd

.include "../../mk/bsd.pkg.mk"
