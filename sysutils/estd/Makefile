# $NetBSD: Makefile,v 1.37 2020/04/29 19:47:46 maya Exp $

DISTNAME=	estd-r11
PKGNAME=	estd-0.11
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://flpsed.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flpsed.org/estd.html
COMMENT=	Dynamically sets the CPU-frequency on SpeedStep and PowerNow CPUs
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-*-i386 \
			NetBSD-*-x86_64 \
			NetBSD-*-powerpc \
			NetBSD-*-mips64el \
			NetBSD-*-earm* NetBSD-*-arm* \
			NetBSD-*-aarch64

RCD_SCRIPTS=		estd
RCD_SCRIPT_SRC.estd=	${WRKSRC}/estd.sh

SUBST_CLASSES+=		rcd
SUBST_STAGE.rcd=	do-configure
SUBST_MESSAGE.rcd=	Fixing startup script.
SUBST_FILES.rcd=	estd.sh
SUBST_VARS.rcd=		PREFIX
SUBST_VARS.rcd+=	ECHO

.include "../../mk/bsd.pkg.mk"
