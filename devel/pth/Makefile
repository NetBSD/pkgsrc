# $NetBSD: Makefile,v 1.17 2000/01/08 20:18:19 rh Exp $
#

DISTNAME=	pth-1.2.2
WRKSRC=		${WRKDIR}/pth-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=pth/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

CONFLICTS=	pth-current-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

.include "../../mk/bsd.pkg.mk"
