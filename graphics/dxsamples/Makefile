# $NetBSD: Makefile,v 1.16 2005/12/26 23:39:32 schmonz Exp $

DISTNAME=	dxsamples-4.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Sample data for Open Visualization Data Explorer

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

DEPENDS+=	dx-[0-9]*:../../graphics/dx

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
