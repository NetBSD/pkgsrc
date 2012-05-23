# $NetBSD: Makefile,v 1.16 2012/05/23 06:26:59 dholland Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

post-build:
	nkf -e ${WRKSRC}/sl.1 > ${WRKSRC}/sl.1.euc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${DESTDIR}${PREFIX}/bin/sl
	${INSTALL_DATA} ${WRKSRC}/sl.1.euc \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/sl.1

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
