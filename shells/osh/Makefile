# $NetBSD: Makefile,v 1.23 2008/12/13 14:14:49 obache Exp $

DISTNAME=	osh-20081213
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/

MAINTAINER=	jan+nbsd@v6shell.org
HOMEPAGE=	http://v6shell.org/
COMMENT=	Port of the Sixth Edition UNIX shell

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_SHELL=		bin/osh

BUILD_TARGET=	oshall
INSTALL_TARGET=	install-oshall

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
