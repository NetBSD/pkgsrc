# $NetBSD: Makefile,v 1.12 2011/01/13 13:39:16 wiz Exp $

DISTNAME=	fwbuilder-2.1.19
PKGNAME=	fwbuilder21-2.1.19
PKGREVISION=	4
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder GUI

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	fwbuilder-[0-9]*

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES+=	datasize
CONFIGURE_ENV+=		QMAKE=${QMAKE:Q}
MAKE_ENV+=		QMAKE=${QMAKE:Q}
QMAKE=			${QTDIR}/bin/qmake

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../security/libfwbuilder21/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
