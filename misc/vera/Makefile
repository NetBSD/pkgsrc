# $NetBSD: Makefile,v 1.11 2003/09/17 15:51:11 hubertf Exp $
# FreeBSD Id: ports/misc/vera/Makefile,v 1.7 2000/11/13 12:44:18 demon Exp

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
