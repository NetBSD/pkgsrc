# $NetBSD: Makefile,v 1.5 2000/01/21 01:30:55 wiz Exp $
#

DISTNAME=	pth-1.3a4
PKGNAME=	${DISTNAME:S/-/-current-/}
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

CONFLICTS=	pth-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

.include "../../mk/bsd.pkg.mk"
