# $NetBSD: Makefile,v 1.14 1999/10/07 06:19:23 rh Exp $
#

DISTNAME=	pth-1.1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=pth/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

CONFLICTS=	pth-current-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

.include "../../mk/bsd.pkg.mk"
