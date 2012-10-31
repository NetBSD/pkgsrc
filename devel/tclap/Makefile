# $NetBSD: Makefile,v 1.2 2012/10/31 11:19:49 asau Exp $

DISTNAME=	tclap-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://tclap.sourceforge.net/
COMMENT=	Templatized C++ Command Line Parser Library
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

pre-configure:
	rm -fr ${WRKSRC}/docs/html/CVS

.include "../../mk/bsd.pkg.mk"
