# $NetBSD: Makefile,v 1.16 2001/10/16 15:08:55 agc Exp $
#

DISTNAME=	mtr-0.42
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtr
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/mtr

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
