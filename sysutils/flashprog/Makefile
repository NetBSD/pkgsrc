# $NetBSD: Makefile,v 1.1 2024/08/31 19:46:15 jakllsch Exp $

DISTNAME=	flashprog-v1.2
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	sysutils
MASTER_SITES=	https://flashprog.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	https://flashprog.org/
COMMENT=	Universal flash utility
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
DEPENDS+=	dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

# XXX Untested
.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lpci
CPPFLAGS+=	-I/${PREFIX}/include
.endif

.include "../../devel/meson/build.mk"
.include "../../misc/libjaylink/buildlink3.mk"
.include "../../devel/libftdi1/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
