# $NetBSD: Makefile,v 1.14 2010/02/11 22:47:52 joerg Exp $
#

DISTNAME=	slurm-0.3.3
CATEGORIES=	net
MASTER_SITES=	http://www.wormulon.net/files/slurm/

MAINTAINER=	mail@eckigesauge.de
HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
COMMENT=	Realtime traffic statistics

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/slurm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slurm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	for theme in black blue cyan foo; do			 \
		${INSTALL_DATA} ${WRKSRC}/themes/$${theme}.theme \
		    ${DESTDIR}${PREFIX}/share/slurm ;		 \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
