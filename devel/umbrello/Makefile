# $NetBSD: Makefile,v 1.2 2003/05/02 11:54:42 wiz Exp $

DISTNAME=	umbrello-1.1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=uml/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://uml.sourceforge.net/
COMMENT= 	Unified Modelling Language diagram program for KDE

USE_BUILDLINK2=		yes
USE_GMAKE=              yes
GNU_CONFIGURE=          yes

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
