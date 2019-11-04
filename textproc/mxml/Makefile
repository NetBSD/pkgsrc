# $NetBSD: Makefile,v 1.7 2019/11/04 21:43:39 rillig Exp $

DISTNAME=	mxml-2.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.msweet.org/files/project3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.minixml.org/
COMMENT=	Small XML parsing library
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=		mxml.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

INSTALL_MAKE_FLAGS+=	BUILDROOT=${DESTDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
