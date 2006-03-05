# $NetBSD: Makefile,v 1.16 2006/03/05 16:27:27 jlam Exp $

DISTNAME=	vera-1.16
CATEGORIES=	misc
MASTER_SITES=	http://home.snafu.de/ohei/FTP/ \
		${MASTER_SITE_GNU:=vera/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgi.snafu.de/ohei/user-cgi-bin/veramain-e.cgi
COMMENT=	Virtual Entity of Relevant Acronyms

USE_TOOLS+=	makeinfo
INFO_FILES=	vera.info

INSTALLATION_DIRS=	info

do-build:
	cd ${WRKSRC} && ${MAKEINFO} vera.texi

do-install:
	${INSTALL_DATA} ${WRKSRC}/vera.info* ${PREFIX}/${INFO_DIR}

.include "../../mk/bsd.pkg.mk"
