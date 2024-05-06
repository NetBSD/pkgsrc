# $NetBSD: Makefile,v 1.11 2024/05/06 08:27:55 jperkin Exp $

DISTNAME=		clex-4.6.4
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.clex.sk/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.clex.sk/
COMMENT=		File manager with a full-screen user interface
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c99
USE_NCURSES=		yes # enter_{bold,reverse,underline}_mode
GNU_CONFIGURE=		yes

# for easy to maintain patches
post-extract:
	cd ${WRKSRC} && ${RM} -f src/*.orig

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
