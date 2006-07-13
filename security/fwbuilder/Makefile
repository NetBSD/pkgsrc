# $NetBSD: Makefile,v 1.14 2006/07/13 17:37:34 bad Exp $

DISTNAME=	fwbuilder-2.0.12
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder GUI

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
UNLIMIT_RESOURCES+=	datasize

QMAKE=		${QTDIR}/bin/qmake
CONFIGURE_ENV+=	QMAKE=${QMAKE:Q}
MAKE_ENV+=	QMAKE=${QMAKE:Q}

.include "../../security/libfwbuilder/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
