# $NetBSD: Makefile,v 1.2 2001/08/26 10:32:19 skrll Exp $
#

DISTNAME=	kyahoo-0.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyahoo/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://kyahoo.sourceforge.net/
COMMENT=	yahoo client for KDE

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
DEPENDS+=       kdebase>=2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
