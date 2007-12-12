# $NetBSD: Makefile,v 1.3 2007/12/12 17:59:21 adam Exp $

DISTNAME=	fwbuilder-2.1.15
PKGNAME=	fwbuilder21-2.1.15
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder GUI

CONFLICTS=	fwbuilder-[0-9]*

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES+=	datasize
CONFIGURE_ENV+=		QMAKE=${QMAKE:Q}
MAKE_ENV+=		QMAKE=${QMAKE:Q}
QMAKE=			${QTDIR}/bin/qmake

.include "../../security/libfwbuilder21/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
