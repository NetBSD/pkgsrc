# $NetBSD: Makefile,v 1.2 1999/07/06 08:05:02 jlam Exp $
#

DISTNAME=	sci.0.3.8
PKGNAME=	sci-0.3.8
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linuxparts.com/software.html

DEPENDS+=       ncurses-4.2:../../devel/ncurses

WRKSRC=         ${WRKDIR}/sci

pre-build:
		-@ln -s ${WRKSRC}/makefile ${WRKSRC}/Makefile >/dev/null

pre-install:
		-@gunzip ${WRKSRC}/sci.1.gz

.include "../../mk/bsd.pkg.mk"
