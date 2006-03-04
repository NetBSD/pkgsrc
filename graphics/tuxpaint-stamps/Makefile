# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:52 jlam Exp $
#

DISTNAME=	tuxpaint-stamps-2004-10-03
PKGNAME=	tuxpaint-stamps-2004.10.03
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	Rubber stamps for Tux Paint

DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint

CONFLICTS+=	tuxpaint<0.9.13

post-install:
	-${FIND} ${PREFIX}/share/tuxpaint/stamps -name CVS -exec \
		 ${RM} -r {} \; 2>/dev/null

.include "../../mk/bsd.pkg.mk"
