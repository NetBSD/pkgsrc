# $NetBSD: Makefile,v 1.4 2001/10/01 03:07:21 jlam Exp $
#

DISTNAME=	expat-1.95.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/conftools/ltconfig
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

DOCDIR=	${PREFIX}/share/doc/html/expat

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
