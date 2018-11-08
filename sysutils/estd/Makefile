# $NetBSD: Makefile,v 1.32 2018/11/08 19:44:26 jakllsch Exp $

DISTNAME=	estd-r11
PKGNAME=	estd-0.11
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/estd.html
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep and PowerNow CPUs
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-i386 NetBSD-[3-9]*-i386 \
			NetBSD-[4-9]*-x86_64 \
			NetBSD-5.99.*-powerpc \
			NetBSD-5.99.*-mips64el \
			NetBSD-[7-9]*-earm* NetBSD-[7-9]*-arm* \
			NetBSD-[7-9]*-aarch64

RCD_SCRIPTS=		estd
RCD_SCRIPT_SRC.estd=	${WRKSRC}/estd.sh

SUBST_CLASSES+=		rcd
SUBST_STAGE.rcd=	do-configure
SUBST_MESSAGE.rcd=	Fixing startup script.
SUBST_FILES.rcd=	estd.sh
SUBST_SED.rcd=		-e 's|@PREFIX@|${PREFIX}|'
SUBST_SED.rcd+=		-e 's|@ECHO@|${ECHO}|'

.include "../../mk/bsd.pkg.mk"
