# $NetBSD: Makefile,v 1.7 2003/06/02 01:18:06 jschauma Exp $
# FreeBSD Id: ports/misc/vera/Makefile,v 1.7 2000/11/13 12:44:18 demon Exp

DISTNAME=	vera-1.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=vera/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://userpage.fu-berlin.de/~oheiabbd/vera-e.html
COMMENT=	Virtual Entity of Relevant Acronyms

INFO_FILES=	vera.info

do-build:
	cd ${WRKSRC} && ${MAKEINFO} vera.texi

do-install:
	${INSTALL_DATA} ${WRKSRC}/vera.info* ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
