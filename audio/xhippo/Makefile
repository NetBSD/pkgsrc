# $NetBSD: Makefile,v 1.1.1.1 1999/02/04 00:06:38 hubertf Exp $
#

DISTNAME=	xhippo
PKGNAME=	xhippo-0.3
CATEGORIES=	audio x11
MASTER_SITES=	http://zenchaos.netpedia.net/software/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://zenchaos.netpedia.net/

DEPENDS=	gtk+-1.1.12:../../x11/gtk

NO_WRKSUBDIR=	YES
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
