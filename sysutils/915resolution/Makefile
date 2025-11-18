# $NetBSD: Makefile,v 1.13 2025/11/18 13:46:12 wiz Exp $

DISTNAME=	915resolution-0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	https://www.aydogan.net/distfiles/sysutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	BIOS VESA resolution utility for 8XX/9XX Intel chips
LICENSE=	public-domain

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 FreeBSD-*-x86_64

USE_TOOLS+=	gmake

MAKE_ENV.NetBSD+=	LDLIBS=-l${MACHINE_ARCH}

INSTALLATION_DIRS=	sbin share/doc/915resolution

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/915resolution

.include "../../mk/bsd.pkg.mk"
