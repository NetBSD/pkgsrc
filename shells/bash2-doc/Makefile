# $NetBSD: Makefile,v 1.12 2005/09/28 20:52:26 rillig Exp $

DISTNAME=	bash-doc-2.05b
PKGNAME=	bash-doc-2.05.2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	Documentation for the GNU Bourne Again Shell

CONFLICTS=	bash<=2.05nb1

WRKSRC=		${WRKDIR}/doc
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	gzip

DOCDIR=		${PREFIX}/share/doc/bash
HTMLDIR=	${PREFIX}/share/doc/html/bash

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_MAN}							\
		${WRKSRC}/article.ps					\
		${WRKSRC}/bashref.ps					\
		${WRKSRC}/article.txt					\
		${PREFIX}/share/doc/bash
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_MAN}							\
		${WRKSRC}/bash.html					\
		${WRKSRC}/bashref.html					\
		${HTMLDIR}
	${GZIP_CMD} ${DOCDIR}/*.ps

.include "../../mk/bsd.pkg.mk"
