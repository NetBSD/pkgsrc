# $NetBSD: Makefile,v 1.3 2009/11/15 13:58:20 drochner Exp $
#

DISTNAME=	mxml-2.6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.easysw.com/pub/mxml/2.6/

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
