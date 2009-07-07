# $NetBSD: Makefile,v 1.2 2009/07/07 21:07:47 joerg Exp $
#

DISTNAME=	mxml-2.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.easysw.com/pub/mxml/2.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.minixml.org/
COMMENT=	Small XML parsing library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	mxml.pc.in

INSTALL_MAKE_FLAGS+=	BUILDROOT=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
