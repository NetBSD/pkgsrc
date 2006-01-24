# $NetBSD: Makefile,v 1.23 2006/01/24 07:32:19 wiz Exp $

DISTNAME=	kbiff-3.8
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kbiff/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.granroth.org/kbiff/index.html
COMMENT= 	Mail notification utility for KDE

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=          yes
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
