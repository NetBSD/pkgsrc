# $NetBSD: Makefile,v 1.4 2005/05/22 20:08:30 jlam Exp $

DISTNAME=	fwbuilder-2.0.6
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder GUI

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
UNLIMIT_RESOURCES+=	datasize

QMAKE=		${QTDIR}/bin/qmake
CONFIGURE_ENV+=	QMAKE="${QMAKE}"
MAKE_ENV+=	QMAKE="${QMAKE}"

.include "../../security/libfwbuilder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
