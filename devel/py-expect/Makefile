# $NetBSD: Makefile,v 1.1.1.1 2001/03/21 23:36:07 jwise Exp $
#

DISTNAME=	ExpectPy-1.9b1
PKGNAME=	py-expect-1.9b1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pub/sourceforge/expectpy/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/expectpy/
COMMENT=	Expect module for Python

DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-python=${LOCALBASE} \
			--with-expect=${LOCALBASE} \
			--with-tcl --enable-shared
INSTALL_TARGET=	installshared

pre-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/python/py-expect
		${INSTALL_DATA} ${WRKSRC}/examples/ask.py ${PREFIX}/share/examples/python/py-expect
		${INSTALL_DATA} ${WRKSRC}/examples/glob.py ${PREFIX}/share/examples/python/py-expect
		${INSTALL_DATA} ${WRKSRC}/examples/ping.py ${PREFIX}/share/examples/python/py-expect
		${INSTALL_DATA} ${WRKSRC}/examples/telnet.py ${PREFIX}/share/examples/python/py-expect
		${INSTALL_DATA} ${WRKSRC}/examples/xping.py ${PREFIX}/share/examples/python/py-expect

.include "../../mk/bsd.pkg.mk"
