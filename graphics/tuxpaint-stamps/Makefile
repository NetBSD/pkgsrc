# $NetBSD: Makefile,v 1.15 2007/09/04 21:22:05 drochner Exp $
#

DISTNAME=	tuxpaint-stamps-2007.07.01
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxpaint.org/
COMMENT=	Rubber stamps for Tux Paint

DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint
CONFLICTS+=	tuxpaint<0.9.13

INSTALL_TARGET=	install-all

post-install:
	-${FIND} ${PREFIX}/share/tuxpaint/stamps -name CVS -exec \
		 ${RM} -r {} \; 2>/dev/null

.include "../../mk/bsd.pkg.mk"
