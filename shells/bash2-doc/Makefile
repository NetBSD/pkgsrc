# $NetBSD: Makefile,v 1.1.1.1 2002/09/26 22:08:12 jlam Exp $

DISTNAME=	bash-doc-2.05
WRKSRC=		${WRKDIR}/doc
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://slc2.ins.cwru.edu/pub/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	The GNU Bourne Again Shell

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
