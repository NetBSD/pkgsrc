# $NetBSD: Makefile,v 1.1.1.1 2001/12/04 10:01:44 wulf Exp $

DISTNAME=	uml-1.0.3-1
PKGNAME=	uml-1.0.3
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=uml/}

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=       http://uml.sourceforge.net/
COMMENT=	UML Modelling tool

BUILD_DEPENDS+= qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
AUTOMAKE_OVERRIDE=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
