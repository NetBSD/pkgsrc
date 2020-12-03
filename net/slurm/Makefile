# $NetBSD: Makefile,v 1.21 2020/12/03 13:04:11 zafer Exp $
#

DISTNAME=	slurm-0.3.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://www.aydogan.net/distfiles/net/

MAINTAINER=	mail@eckigesauge.de
#HOMEPAGE=	http://www.raisdorf.net/projects/slurm/
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
