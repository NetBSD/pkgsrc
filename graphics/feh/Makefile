# $NetBSD: Makefile,v 1.12 2003/07/21 16:51:38 martti Exp $
#

DISTNAME=	feh-1.2.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.linuxbrit.co.uk/feh/
COMMENT=	Advanced image viewer

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../devel/giblib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
