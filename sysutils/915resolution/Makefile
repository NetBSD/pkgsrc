# $NetBSD: Makefile,v 1.4 2009/08/19 08:41:45 ghen Exp $
#

DISTNAME=	915resolution-0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/stomljen/
COMMENT=	BIOS VESA resolution utility for 8XX/9XX Intel chips

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	LDLIBS=-l${MACHINE_ARCH}
.endif

INSTALLATION_DIRS=	sbin share/doc/915resolution

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/915resolution

.include "../../mk/bsd.pkg.mk"
