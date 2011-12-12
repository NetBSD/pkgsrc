# $NetBSD: Makefile,v 1.6 2011/12/12 14:57:46 abs Exp $
#

DISTNAME=	915resolution-0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE:Q}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://915resolution.mango-lang.org/
COMMENT=	BIOS VESA resolution utility for 8XX/9XX Intel chips
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 FreeBSD-*-x86_64 DragonFly-*-i386

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	LDLIBS=-l${MACHINE_ARCH}
.endif

INSTALLATION_DIRS=	sbin share/doc/915resolution

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/915resolution

.include "../../mk/bsd.pkg.mk"
