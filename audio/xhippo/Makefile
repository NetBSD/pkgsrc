# $NetBSD: Makefile,v 1.5 1999/05/02 14:35:56 tron Exp $
#

DISTNAME=	xhippo-0.6
CATEGORIES=	audio x11
MASTER_SITES=	http://zenchaos.netpedia.net/software/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://zenchaos.netpedia.net/

DEPENDS=	gtk+-1.2.2:../../x11/gtk

USE_X11=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xhippo
	${MV} ${PREFIX}/etc/xhippo.config ${PREFIX}/share/doc/xhippo/xhippo.config.example
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/LIESMICH ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README.fvwm2 ${PREFIX}/share/doc/xhippo

.include "../../mk/bsd.pkg.mk"
