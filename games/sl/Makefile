# $NetBSD: Makefile,v 1.2 2000/06/06 01:26:11 minoura Exp $
#
# This patch won't work well :p
#PATCH_SITES=	http://ecssg.ec.tmit.ac.jp/~izumi/sl/
#PATCHFILES=	sl5.patch
#PATCH_DIST_STRIP= -p1

DISTNAME=	sl
PKGNAME=	sl-3.03
CATEGORIES=	games
MASTER_SITES=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/sl/
EXTRACT_SUFX=	.tar

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/

BUILD_DEPENDS=	nkf:../../japanese/nkf

ALL_TARGET=	sl

post-build:
	nkf -e ${WRKSRC}/sl.1 > ${WRKSRC}/sl.1.euc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${PREFIX}/bin/sl
	${INSTALL_DATA} ${WRKSRC}/sl.1.euc ${PREFIX}/man/ja_JP.EUC/man1/sl.1

.include "../../mk/bsd.pkg.mk"
