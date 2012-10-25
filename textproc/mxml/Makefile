# $NetBSD: Makefile,v 1.4 2012/10/25 06:56:08 asau Exp $
#

DISTNAME=	mxml-2.6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.easysw.com/pub/mxml/2.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.minixml.org/
COMMENT=	Small XML parsing library

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	mxml.pc.in

INSTALL_MAKE_FLAGS+=	BUILDROOT=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
