# $NetBSD: Makefile,v 1.1.1.1 2007/06/08 06:07:25 pooka Exp $
#

DISTNAME=	ipbt-r7471
PKGNAME=	ipbt-7471
CATEGORIES=	misc
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/ipbt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/ipbt/
COMMENT=	High-tech ttyrec player

USE_TOOLS+=	perl
BUILD_TARGET=	ipbt

INCOMPAT_CURSES=NetBSD-*-*

post-build:
	${SED} -e "s,/usr/bin/perl,${PERL5}," \
	    ${WRKSRC}/ttydump > ${WRKSRC}/ttydump.path
	${SED} -e "s,/usr/bin/perl,${PERL5}," \
	    ${WRKSRC}/ttygrep > ${WRKSRC}/ttygrep.path

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipbt ${PREFIX}/bin/ipbt
	${INSTALL_MAN} ${WRKSRC}/ipbt.1 ${PREFIX}/${PKGMANDIR}/man1/ipbt.1
	${INSTALL_SCRIPT} ${WRKSRC}/ttydump.path ${PREFIX}/bin/ttydump
	${INSTALL_SCRIPT} ${WRKSRC}/ttygrep.path ${PREFIX}/bin/ttygrep

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
