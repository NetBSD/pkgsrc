# $NetBSD: Makefile,v 1.2 2001/07/23 20:08:28 skrll Exp $
#

DISTNAME=	cervisia-1.4.1
CATEGORIES=	kde devel
MASTER_SITES=	http://prdownloads.sourceforge.net/cervisia/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://cervisia.sourceforge.net/
COMMENT=	Graphical frontend for the CVS client

BUILD_DEPENDS+=	{qt2-designer>=2.3.0,qt2-designer-kde>=2.3.0}:../../x11/qt2-designer
DEPENDS+=	kdelibs-2.1nb1:../../x11/kdelibs2

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
