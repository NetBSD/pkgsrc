# $NetBSD: Makefile,v 1.19 2024/05/06 08:40:29 jperkin Exp $
#

DISTNAME=	ipbt-r8765
PKGNAME=	ipbt-8765
PKGREVISION=	12
CATEGORIES=	misc
# The upstream distfile is apparently rebuilt every night with
# newly regenerated docs that have different timestamps. Use the
# copy cached on ftp.NetBSD.org so the checksum works.
MASTER_SITES=	${MASTER_SITE_LOCAL}
DIST_SUBDIR=	ipbt-20100101
#MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/ipbt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/ipbt/
COMMENT=	High-tech ttyrec player

USE_TOOLS+=		perl
REPLACE_PERL=		ttydump ttygrep
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILD_TARGET=		ipbt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipbt ${DESTDIR}${PREFIX}/bin/ipbt
	${INSTALL_MAN} ${WRKSRC}/ipbt.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ipbt.1
	${INSTALL_SCRIPT} ${WRKSRC}/ttydump ${DESTDIR}${PREFIX}/bin/ttydump
	${INSTALL_SCRIPT} ${WRKSRC}/ttygrep ${DESTDIR}${PREFIX}/bin/ttygrep

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
