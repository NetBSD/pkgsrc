# $NetBSD: Makefile,v 1.10 1999/11/03 04:02:56 hubertf Exp $
#

DISTNAME=	xhippo-2.0
CATEGORIES=	audio x11
MASTER_SITES=	http://zenchaos.netpedia.net/software/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://zenchaos.netpedia.net/

DEPENDS=	gtk+-1.2.*:../../x11/gtk

USE_X11=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/xhippo.config ${PREFIX}/share/doc/xhippo/xhippo.config.example
	${INSTALL_DATA} ${WRKSRC}/xhippo.gtkrc ${PREFIX}/share/doc/xhippo/xhippo.gtkrc
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/README.fvwm2 ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.ps.gz ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.txt.gz ${PREFIX}/share/doc/xhippo
	${INSTALL_DATA} ${WRKSRC}/doc/xhippo.sgml ${PREFIX}/share/doc/xhippo

.include "../../mk/bsd.pkg.mk"
