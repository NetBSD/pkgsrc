# $NetBSD: Makefile,v 1.1.1.1 1999/08/12 18:01:16 rh Exp $
#

DISTNAME=	pth-1.1b3
PKGNAME=	pth-current-1.1b3
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

CONFLICTS=	pth-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

.include "../../mk/bsd.pkg.mk"
