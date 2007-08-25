# $NetBSD: Makefile,v 1.14 2007/08/25 10:00:53 taca Exp $

DISTNAME=	estd-r5
PKGNAME=	estd-0.5
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.elektro-eel.org/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.elektro-eel.org/
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep-enabled CPUs

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-i386 NetBSD-[3-9]*-i386 \
			NetBSD-[4-9]*-x86_64 DragonFly-*-i386

RCD_SCRIPTS=		estd
RCD_SCRIPT_SRC.estd=	${WRKSRC}/estd.sh

SUBST_CLASSES+=		rc.d
SUBST_STAGE.rc.d=	do-configure
SUBST_MESSAGE.rc.d=	Fixing startup script.
SUBST_FILES.rc.d=	estd.sh
SUBST_SED.rc.d=		-e 's|@PREFIX@|${PREFIX}|'
SUBST_SED.rc.d+=	-e 's|@ECHO@|${ECHO}|'

.include "../../mk/bsd.pkg.mk"
