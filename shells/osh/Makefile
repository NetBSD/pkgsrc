# $NetBSD: Makefile,v 1.7 2004/04/25 15:49:57 minskim Exp $
# FreeBSD Id: ports/shells/osh/Makefile,v 1.3 2002/01/29 11:58:43 knu Exp

DISTNAME=	osh-040421
CATEGORIES=	shells
MASTER_SITES=	http://jneitzel.sdf1.org/osh/src/

HOMEPAGE=	http://jneitzel.sdf1.org/osh/
MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Implementation of the UNIX 6th Edition shell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
PKG_SHELL=	${PREFIX}/bin/osh

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
