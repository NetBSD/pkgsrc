# $NetBSD: Makefile,v 1.12 2023/12/13 14:53:44 zafer Exp $
#

DISTNAME=	855resolution-0.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.aydogan.net/distfiles/sysutils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.orange.fr/apoirier/
COMMENT=	BIOS VESA resolution utility for 855/865/915 Intel chips

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386

WRKSRC=		${WRKDIR}/855resolution
USE_TOOLS+=	gmake

MAKE_ENV.NetBSD+=	EXTRA_LIBS=-l${MACHINE_ARCH}

INSTALLATION_DIRS=	sbin share/doc/855resolution

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/855resolution

.include "../../mk/bsd.pkg.mk"
