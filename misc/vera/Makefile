# $NetBSD: Makefile,v 1.3 2001/03/16 20:53:04 zuntum Exp $
# FreeBSD Id: ports/misc/vera/Makefile,v 1.7 2000/11/13 12:44:18 demon Exp

DISTNAME=	vera-1.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=vera/}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://userpage.fu-berlin.de/~oheiabbd/vera-e.html
COMMENT=	Virtual Entity of Relevant Acronyms

do-build:
		cd ${WRKSRC} && makeinfo vera.texi

do-install:
		${INSTALL_DATA} ${WRKSRC}/vera.info* ${PREFIX}/info

post-install:
		install-info ${PREFIX}/info/vera.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
