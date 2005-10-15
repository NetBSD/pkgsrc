# $NetBSD: Makefile,v 1.17 2005/10/15 22:16:05 tonio Exp $

DISTNAME=	figlet222
PKGNAME=	figlet-2.2.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/program/unix/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://www.figlet.org/
COMMENT=	Print text banners in fancy ASCII art characters

PKG_INSTALLATION_TYPES= overwrite pkgviews

pre-install:
		${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
		${INSTALL_MAN_DIR} ${PREFIX}/man/man6

.include "../../mk/bsd.pkg.mk"
