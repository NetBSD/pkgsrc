# $NetBSD: Makefile,v 1.28 2025/12/11 09:26:46 wiz Exp $

DISTNAME=	figlet-2.2.5
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.figlet.org/
COMMENT=	Print text banners in fancy ASCII art characters
LICENSE=	modified-bsd

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
