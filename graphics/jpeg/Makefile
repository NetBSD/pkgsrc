# $NetBSD: Makefile,v 1.13 1998/11/30 18:58:09 tv Exp $
#

DISTNAME=	jpegsrc.v6b
PKGNAME=	jpeg-6b
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.ijg.org/

CONFLICTS=	jpeg-6a

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET= install install-lib

WRKSRC=		${WRKDIR}/jpeg-6b

.include "../../mk/bsd.pkg.mk"
