# $NetBSD: Makefile,v 1.19 2007/05/12 16:18:55 heinz Exp $

DISTNAME=	osh-20070324
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://jneitzel.sdf1.org/osh/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jneitzel.sdf1.org/osh/
COMMENT=	Implementation of the UNIX 6th Edition shell

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_SHELL=		bin/osh

BUILD_TARGET=	oshall
INSTALL_TARGET=	install-oshall
TEST_TARGET=	check

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
