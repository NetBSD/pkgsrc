# $NetBSD: Makefile,v 1.8 2004/10/14 16:27:17 ben Exp $
#

DISTNAME=	slurm-0.3.3
CATEGORIES=	net
MASTER_SITES=	http://www.raisdorf.net/files/slurm/

MAINTAINER=	mail@eckigesauge.de
HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
COMMENT=	Realtime traffic statistics

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slurm.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/slurm
	for theme in black blue cyan foo; do								\
		${INSTALL_DATA} ${WRKSRC}/themes/$${theme}.theme ${PREFIX}/share/slurm ;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
