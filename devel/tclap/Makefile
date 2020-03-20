# $NetBSD: Makefile,v 1.5 2020/03/20 11:57:33 nia Exp $

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

CONFIGURE_ARGS+=	--disable-doxygen

pre-configure:
	rm -fr ${WRKSRC}/docs/html/CVS

.include "../../mk/bsd.pkg.mk"
