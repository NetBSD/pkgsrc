# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:46:10 jlam Exp $
#

DISTNAME=	sl
PKGNAME=	sl-3.03p5
CATEGORIES=	games
MASTER_SITES=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/sl/
EXTRACT_SUFX=	.tar

PATCH_SITES=	http://ecssg.ec.tmit.ac.jp/~izumi/sl/
PATCHFILES=	sl5.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/
COMMENT=	Animated SL that runs across the terminal when you type `sl' instead of `ls'

BUILD_DEPENDS=	nkf-1.7:../../converters/nkf

post-build:
	nkf -e ${WRKSRC}/sl.1 > ${WRKSRC}/sl.1.euc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${PREFIX}/bin/sl
	${INSTALL_DATA} ${WRKSRC}/sl.1.euc ${PREFIX}/man/ja_JP.EUC/man1/sl.1

.include "../../mk/bsd.pkg.mk"
