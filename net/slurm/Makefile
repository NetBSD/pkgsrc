# $NetBSD: Makefile,v 1.1.1.1 2003/03/04 16:22:06 hubertf Exp $
#

DISTNAME=	slurm-0.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.raisdorf.net/files/code/

MAINTAINER=	mail@eckigesauge.de
HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
COMMENT=	Realtime traffic statistics

USE_BUILDLINK2=	YES
NO_CONFIGURE=	YES

USE_NCURSES=	# use_default_colors

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slurm.1 ${PREFIX}/man/man1

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
