# $NetBSD: Makefile,v 1.9 2008/08/25 14:46:29 joerg Exp $
#

DISTNAME=	855resolution-0.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.orange.fr/apoirier/
COMMENT=	BIOS VESA resolution utility for 855/865/915 Intel chips

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386

WRKSRC=		${WRKDIR}/855resolution
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	EXTRA_LIBS=-l${MACHINE_ARCH}
.endif

INSTALLATION_DIRS=	sbin share/doc/855resolution

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/855resolution

.include "../../mk/bsd.pkg.mk"
