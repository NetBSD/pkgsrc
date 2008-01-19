# $NetBSD: Makefile,v 1.20 2008/01/19 12:08:29 obache Exp $

DISTNAME=	osh-20080109
CATEGORIES=	shells
MASTER_SITES=	http://www.v6shell.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.v6shell.org/
COMMENT=	Implementation of the UNIX 6th Edition shell

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_SHELL=		bin/osh

BUILD_TARGET=	oshall
INSTALL_TARGET=	install-oshall

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
