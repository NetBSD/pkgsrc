# $NetBSD: Makefile,v 1.16 2005/03/24 21:12:57 wiz Exp $

DISTNAME=	figlet221
PKGNAME=	figlet-2.2.1
PKGREVISION=	2
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
