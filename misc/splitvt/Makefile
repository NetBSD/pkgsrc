# $NetBSD: Makefile,v 1.12 2004/04/11 17:31:50 snj Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/02 08:39:12 obrien Exp
#

DISTNAME=		splitvt-1.6.3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/console/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Run two shells in a split window/terminal

ALL_TARGET=
CONFIGURE_SCRIPT=	./Configure
HAS_CONFIGURE=		yes
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
