# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:32 wiz Exp $

DISTNAME=	fwbuilder-2.0.10
PKGREVISION=	1
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
CONFIGURE_ENV+=	QMAKE=${QMAKE:Q}
MAKE_ENV+=	QMAKE=${QMAKE:Q}

# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full

.include "../../security/libfwbuilder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
