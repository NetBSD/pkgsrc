# $NetBSD: Makefile,v 1.23 2012/08/15 17:45:45 drochner Exp $

DISTNAME=	figlet-2.2.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Print text banners in fancy ASCII art characters
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
