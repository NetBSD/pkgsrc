# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:23 wiz Exp $
#

DISTNAME=	kchm-0.6.5
PKGREVISION=	1
CATEGORIES=	kde misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kchmnew/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kchmnew.sourceforge.net/
COMMENT=	KDE CHM file viewer

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
