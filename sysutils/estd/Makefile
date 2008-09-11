# $NetBSD: Makefile,v 1.15 2008/09/11 09:51:54 adam Exp $

DISTNAME=	estd-r6
PKGNAME=	estd-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.elektro-eel.org/software/estd/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.elektro-eel.org/
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep-enabled CPUs

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-i386 NetBSD-[3-9]*-i386 \
			NetBSD-[4-9]*-x86_64 DragonFly-*-i386

RCD_SCRIPTS=		estd
RCD_SCRIPT_SRC.estd=	${WRKSRC}/estd.sh

SUBST_CLASSES+=		rcd
SUBST_STAGE.rcd=	do-configure
SUBST_MESSAGE.rcd=	Fixing startup script.
SUBST_FILES.rcd=	estd.sh
SUBST_SED.rcd=		-e 's|@PREFIX@|${PREFIX}|'
SUBST_SED.rcd+=		-e 's|@ECHO@|${ECHO}|'

.include "../../mk/bsd.pkg.mk"
