# $NetBSD: Makefile,v 1.10 2005/03/08 09:05:46 adam Exp $

DISTNAME=	osh-050131
CATEGORIES=	shells
MASTER_SITES=	http://jneitzel.sdf1.org/osh/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jneitzel.sdf1.org/osh/
COMMENT=	Implementation of the UNIX 6th Edition shell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
PKG_SHELL=		${PREFIX}/bin/osh

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
