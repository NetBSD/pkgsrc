# $NetBSD: Makefile,v 1.10 2004/01/23 21:50:44 jmmv Exp $

DISTNAME=	umbrello-1.1.1
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=uml/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://uml.sourceforge.net/
COMMENT= 	Unified Modelling Language diagram program for KDE

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
