# $NetBSD: Makefile,v 1.12 2001/05/09 11:29:11 agc Exp $
#

DISTNAME=	xhippo-2.0
CATEGORIES=	audio x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://zenchaos.netpedia.net/
COMMENT=	Generic playlist manager for UNIX

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
