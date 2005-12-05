# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:17 rillig Exp $
#

DISTNAME=	sl
PKGNAME=	sl-3.03p5
CATEGORIES=	games
MASTER_SITES=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/sl/
EXTRACT_SUFX=	.tar

PATCH_SITES=	http://www.linet.gr.jp/~izumi/sl/
PATCHFILES=	sl5.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/
COMMENT=	Animated SL that runs across the terminal when you type `sl'

DIST_SUBDIR=	${PKGNAME_NOREV}

BUILD_DEPENDS+=	nkf-[0-9]*:../../converters/nkf

INSTALLATION_DIRS=	bin man/ja_JP.EUC/man1

post-build:
	nkf -e ${WRKSRC}/sl.1 > ${WRKSRC}/sl.1.euc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${PREFIX}/bin/sl
	${INSTALL_DATA} ${WRKSRC}/sl.1.euc ${PREFIX}/man/ja_JP.EUC/man1/sl.1

.include "../../mk/bsd.pkg.mk"
