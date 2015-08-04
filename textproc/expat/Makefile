# $NetBSD: Makefile,v 1.29 2015/08/04 08:47:19 tnn Exp $
#

DISTNAME=	expat-2.1.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C
LICENSE=	mit

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE+=	expat.pc.in

DOCDIR=	${PREFIX}/share/doc/html/expat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
