# $NetBSD: Makefile,v 1.12 2005/03/24 21:12:58 wiz Exp $

DISTNAME=	vera-1.11
CATEGORIES=	misc
MASTER_SITES=	http://home.snafu.de/ohei/FTP/ \
		${MASTER_SITE_GNU:=vera/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://userpage.fu-berlin.de/~oheiabbd/vera-e.html
COMMENT=	Virtual Entity of Relevant Acronyms

USE_MAKEINFO=	YES
INFO_FILES=	vera.info

do-build:
	cd ${WRKSRC} && ${MAKEINFO} vera.texi

do-install:
	${INSTALL_DATA} ${WRKSRC}/vera.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
