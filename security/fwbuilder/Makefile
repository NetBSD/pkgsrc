# $NetBSD: Makefile,v 1.1.1.1 2005/02/24 11:03:22 bad Exp $

DISTNAME=	fwbuilder-2.0.5
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder GUI

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++
UNLIMIT_RESOURCES+=	datasize

QMAKE=		${QTDIR}/bin/qmake
CONFIGURE_ENV+=	QMAKE="${QMAKE}"
MAKE_ENV+=	QMAKE="${QMAKE}"

.include "../../security/libfwbuilder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
