# $NetBSD: Makefile,v 1.4 2000/03/16 13:50:13 wiz Exp $
#

DISTNAME=	sci.0.3.8
PKGNAME=	sci-0.3.8
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linuxparts.com/software.html

DEPENDS+=       ncurses>=4.2:../../devel/ncurses

WRKSRC=         ${WRKDIR}/sci

pre-build:
		-@${LN} -s ${WRKSRC}/makefile ${WRKSRC}/Makefile >/dev/null

pre-install:
		-@${GUNZIP_CMD} ${WRKSRC}/sci.1.gz

.include "../../mk/bsd.pkg.mk"
