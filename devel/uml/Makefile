# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:34 tv Exp $

DISTNAME=	uml-1.0.3-1
PKGNAME=	uml-1.0.3
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=uml/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://uml.sourceforge.net/
COMMENT=	UML Modelling tool

BUILD_DEPENDS+= qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdelibs2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
