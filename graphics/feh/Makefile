# $NetBSD: Makefile,v 1.9 2003/06/05 08:22:32 wiz Exp $
#

DISTNAME=	feh-1.2.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.linuxbrit.co.uk/feh/
COMMENT=	advanced image viewer

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../devel/giblib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
