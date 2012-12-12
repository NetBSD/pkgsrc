# $NetBSD: Makefile,v 1.21 2012/12/12 10:44:11 wiz Exp $

DISTNAME=	estd-r7
PKGNAME=	estd-0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/estd.html
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep and PowerNow CPUs
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-i386 NetBSD-[3-9]*-i386 \
			NetBSD-[4-9]*-x86_64 DragonFly-*-i386 \
			NetBSD-5.99.*-powerpc \
			NetBSD-5.99.*-mips64el

RCD_SCRIPTS=		estd
RCD_SCRIPT_SRC.estd=	${WRKSRC}/estd.sh

SUBST_CLASSES+=		rcd
SUBST_STAGE.rcd=	do-configure
SUBST_MESSAGE.rcd=	Fixing startup script.
SUBST_FILES.rcd=	estd.sh
SUBST_SED.rcd=		-e 's|@PREFIX@|${PREFIX}|'
SUBST_SED.rcd+=		-e 's|@ECHO@|${ECHO}|'

.include "../../mk/bsd.pkg.mk"
