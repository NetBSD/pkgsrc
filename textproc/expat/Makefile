# $NetBSD: Makefile,v 1.7 2002/09/17 21:06:15 drochner Exp $
#

DISTNAME=	expat-1.95.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		YES
USE_BUILDLINK2=		YES

DOCDIR=	${PREFIX}/share/doc/html/expat

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
