# $NetBSD: Makefile,v 1.17 2019/10/12 20:51:48 rillig Exp $

DISTNAME=	bash-doc-2.05b
PKGNAME=	bash-doc-2.05.2
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU:=bash/}
MASTER_SITES+=	ftp://ftp.cwru.edu/pub/bash/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bash/bash.html
COMMENT=	Documentation for the GNU Bourne Again Shell

CONFLICTS=	bash<=2.05nb1

WRKSRC=		${WRKDIR}/doc
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	gzip

DOCDIR=		${PREFIX}/share/doc/bash
DOCDIR_FILES=	article.ps bashref.ps article.txt bash.html bashref.html

INSTALLATION_DIRS=	${DOCDIR}

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCDIR_FILES} ${DESTDIR}${DOCDIR}
	${GZIP_CMD} ${DESTDIR}${DOCDIR}/*.ps

.include "../../mk/bsd.pkg.mk"
