# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:09 joerg Exp $
#

DISTNAME=	kchm-0.6.5
PKGREVISION=	2
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
