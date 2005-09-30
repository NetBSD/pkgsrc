# $NetBSD: Makefile,v 1.11 2005/09/30 04:56:27 minskim Exp $
#

DISTNAME=	slurm-0.3.3
CATEGORIES=	net
MASTER_SITES=	http://www.wormulon.net/files/code/slurm/

MAINTAINER=	mail@eckigesauge.de
HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
COMMENT=	Realtime traffic statistics

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slurm.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/slurm
	for theme in black blue cyan foo; do								\
		${INSTALL_DATA} ${WRKSRC}/themes/$${theme}.theme ${PREFIX}/share/slurm ;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
