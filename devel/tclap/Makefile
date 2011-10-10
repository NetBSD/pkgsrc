# $NetBSD: Makefile,v 1.1.1.1 2011/10/10 13:15:31 adam Exp $

DISTNAME=	tclap-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://tclap.sourceforge.net/
COMMENT=	Templatized C++ Command Line Parser Library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

pre-configure:
	rm -fr ${WRKSRC}/docs/html/CVS

.include "../../mk/bsd.pkg.mk"
