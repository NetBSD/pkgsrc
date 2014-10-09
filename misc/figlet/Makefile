# $NetBSD: Makefile,v 1.25 2014/10/09 14:06:42 wiz Exp $

DISTNAME=	figlet-2.2.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Print text banners in fancy ASCII art characters
LICENSE=	modified-bsd

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
