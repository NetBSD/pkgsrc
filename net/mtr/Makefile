# $NetBSD: Makefile,v 1.22 2001/12/04 06:15:00 jlam Exp $
#

DISTNAME=	mtr-0.42
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtr
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/mtr

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
