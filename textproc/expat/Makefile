# $NetBSD: Makefile,v 1.3 2001/08/07 11:16:55 drochner Exp $
#

DISTNAME=	expat-1.95.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/conftools/ltconfig
USE_GMAKE=	yes

DOCDIR=	${PREFIX}/share/doc/html/expat

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
