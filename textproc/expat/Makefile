# $NetBSD: Makefile,v 1.11 2004/01/05 23:43:06 jlam Exp $
#

DISTNAME=	expat-1.95.6
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		YES
USE_BUILDLINK3=		YES

DOCDIR=	${PREFIX}/share/doc/html/expat

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
