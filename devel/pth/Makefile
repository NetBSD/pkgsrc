# $NetBSD: Makefile,v 1.6 1999/08/06 01:03:32 sakamoto Exp $
#

DISTNAME=	pth-1.0.4
CATEGORIES=	devel
#MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/
MASTER_SITES=	${MASTER_SITE_GNU:=pth/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

.include "../../mk/bsd.pkg.mk"
