# $NetBSD: Makefile,v 1.4 2003/06/02 01:17:01 jschauma Exp $

DISTNAME=	bash-doc-2.05b
PKGNAME=	bash-doc-2.05.2
WRKSRC=		${WRKDIR}/doc
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	documentation for the GNU Bourne Again Shell

CONFLICTS=	bash<=2.05nb1

USE_BUILDLINK2=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

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
