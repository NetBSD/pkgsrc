# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:21 jlam Exp $
#

DISTNAME=		easymenu-0.7.2
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.mreriksson.net/pub/easymenu/

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://www.mrEriksson.net/dev/
COMMENT=		Software used to generate menu systems

NO_BUILD=		# defined

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/easymenu ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/easymenu
	${INSTALL_DATA_DIR} ${PREFIX}/share/easymenu/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/easymenu/etc/menus-sample
	${INSTALL_SCRIPT} ${WRKSRC}/easymenu-demo.sh \
		${PREFIX}/share/easymenu/
	${INSTALL_SCRIPT} ${WRKSRC}/easymenu-demo-bash.sh \
		${PREFIX}/share/easymenu/
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/easymenu/
	${INSTALL_DATA} ${WRKSRC}/CHANGES \
		${PREFIX}/share/easymenu/
	${INSTALL_DATA} ${WRKSRC}/etc/easymenu.conf-minimode \
		${PREFIX}/share/easymenu/etc/
	${INSTALL_DATA} ${WRKSRC}/etc/easymenu.conf-sample \
		${PREFIX}/share/easymenu/etc/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo \
		${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo.1 \
		${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo.2 \
		${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo.3 \
		${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/main \
		${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/post-demo \
		${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/pre-demo \
		${PREFIX}/share/easymenu/etc/menus-sample/

.include "../../mk/bsd.pkg.mk"
