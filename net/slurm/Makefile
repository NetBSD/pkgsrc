# $NetBSD: Makefile,v 1.6 2004/04/25 07:34:28 snj Exp $
#

DISTNAME=	slurm-0.3.1
CATEGORIES=	net
MASTER_SITES=	http://www.raisdorf.net/files/code/

MAINTAINER=	mail@eckigesauge.de
HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
COMMENT=	Realtime traffic statistics

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

post-patch:
	${SED} -e s,@PREFIX@,${PREFIX}, ${WRKSRC}/theme.c > ${WRKSRC}/theme.c.sed
	${MV} ${WRKSRC}/theme.c.sed ${WRKSRC}/theme.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slurm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slurm.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/slurm
	for theme in blue cyan foo; do								\
		${INSTALL_DATA} ${WRKSRC}/themes/$${theme}.theme ${PREFIX}/share/slurm ;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
