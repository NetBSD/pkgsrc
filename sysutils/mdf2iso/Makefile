# $NetBSD: Makefile,v 1.8 2021/07/20 21:27:08 fcambus Exp $
#

DISTNAME=	mdf2iso_0.3.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig$//}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/m/mdf2iso/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://mdf2iso.berlios.de/
COMMENT=	Utility to convert Alcohol 120% images to ISO-9660 format
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

WRKSRC=			${WRKDIR}/mdf2iso-0.3.1

do-build:
	cd ${WRKSRC} && cc ${CFLAGS} src/mdf2iso.c -o mdf2iso

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdf2iso ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
