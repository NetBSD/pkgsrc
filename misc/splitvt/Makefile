# $NetBSD: Makefile,v 1.8 2001/02/17 18:09:25 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/02 08:39:12 obrien Exp
#

DISTNAME=		splitvt-1.6.3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/console/}

MAINTAINER=		packages@netbsd.org
COMMENT=		run two shells in a split window/terminal

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
