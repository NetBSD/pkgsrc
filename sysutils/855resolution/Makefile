# $NetBSD: Makefile,v 1.8 2006/11/13 15:00:56 obache Exp $
#

DISTNAME=	855resolution-0.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.orange.fr/apoirier/
COMMENT=	BIOS VESA resolution utility for 855/865/915 Intel chips

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386

WRKSRC=		${WRKDIR}/855resolution
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	EXTRA_LIBS=-l${MACHINE_ARCH}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/855resolution
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/855resolution

.include "../../mk/bsd.pkg.mk"
