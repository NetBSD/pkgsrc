# $NetBSD: Makefile,v 1.20 2009/12/10 21:13:07 abs Exp $

DISTNAME=	figlet222
PKGNAME=	figlet-2.2.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Print text banners in fancy ASCII art characters

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

.include "../../mk/bsd.pkg.mk"
