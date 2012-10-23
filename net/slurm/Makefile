# $NetBSD: Makefile,v 1.16 2012/10/23 17:19:09 asau Exp $
#

DISTNAME=	slurm-0.3.3
CATEGORIES=	net
MASTER_SITES=	http://distfiles.aydogan.net/net/

MAINTAINER=	mail@eckigesauge.de
HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
COMMENT=	Realtime traffic statistics

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
