# $NetBSD: Makefile,v 1.10 2004/10/07 14:54:40 wiz Exp $
#

DISTNAME=	tuxpaint-stamps-2004-10-03
PKGNAME=	tuxpaint-stamps-2004.10.03
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	Rubber stamps for Tux Paint

DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint

CONFLICTS+=	tuxpaint<0.9.13

post-install:
	-${FIND} ${PREFIX}/share/tuxpaint/stamps -name CVS -exec \
		 ${RM} -r {} \; 2>/dev/null

.include "../../mk/bsd.pkg.mk"
