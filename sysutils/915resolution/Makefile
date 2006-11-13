# $NetBSD: Makefile,v 1.2 2006/11/13 04:15:02 obache Exp $
#

DISTNAME=	915resolution-0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/stomljen/
COMMENT=	BIOS VESA resolution utility for 8XX/9XX Intel chips

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	LDLIBS=-l${MACHINE_ARCH}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/915resolution
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/915resolution

.include "../../mk/bsd.pkg.mk"
