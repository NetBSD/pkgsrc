# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:37 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/02 08:39:12 obrien Exp
#

DISTNAME=	splitvt-1.6.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/console

MAINTAINER=     obrien@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=
MAN1=		splitvt.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
