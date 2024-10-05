# $NetBSD: Makefile,v 1.12 2024/10/05 08:02:56 nia Exp $

DISTNAME=	915resolution-0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE:Q}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.aydogan.net/distfiles/sysutils/
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
