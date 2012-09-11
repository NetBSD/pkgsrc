# $NetBSD: Makefile,v 1.15 2012/09/11 23:25:07 asau Exp $

DISTNAME=	bash-doc-2.05b
PKGNAME=	bash-doc-2.05.2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/} \
		ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	Documentation for the GNU Bourne Again Shell

CONFLICTS=	bash<=2.05nb1

WRKSRC=		${WRKDIR}/doc
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	gzip

DOCDIR=		${PREFIX}/share/doc/bash
HTMLDIR=	${PREFIX}/share/doc/html/bash

INSTALLATION_DIRS=	${DOCDIR} ${HTMLDIR}

do-install:
	${INSTALL_MAN}							\
		${WRKSRC}/article.ps					\
		${WRKSRC}/bashref.ps					\
		${WRKSRC}/article.txt					\
		${DESTDIR}${PREFIX}/share/doc/bash
	${INSTALL_MAN}							\
		${WRKSRC}/bash.html					\
		${WRKSRC}/bashref.html					\
		${DESTDIR}${HTMLDIR}
	${GZIP_CMD} ${DESTDIR}${DOCDIR}/*.ps

.include "../../mk/bsd.pkg.mk"
