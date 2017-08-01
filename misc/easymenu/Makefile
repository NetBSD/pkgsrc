# $NetBSD: Makefile,v 1.9 2017/08/01 16:47:40 wiz Exp $
#

DISTNAME=		easymenu-0.7.2
CATEGORIES=		misc
MASTER_SITES=		# ftp://ftp.mreriksson.net/pub/easymenu/

MAINTAINER=		ola@mrEriksson.net
#HOMEPAGE=		http://www.mreriksson.net/dev/easymenu/
COMMENT=		Software used to generate menu systems

NO_BUILD=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/easymenu ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/easymenu
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/easymenu/etc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample
	${INSTALL_SCRIPT} ${WRKSRC}/easymenu-demo.sh \
		${DESTDIR}${PREFIX}/share/easymenu/
	${INSTALL_SCRIPT} ${WRKSRC}/easymenu-demo-bash.sh \
		${DESTDIR}${PREFIX}/share/easymenu/
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/easymenu/
	${INSTALL_DATA} ${WRKSRC}/CHANGES \
		${DESTDIR}${PREFIX}/share/easymenu/
	${INSTALL_DATA} ${WRKSRC}/etc/easymenu.conf-minimode \
		${DESTDIR}${PREFIX}/share/easymenu/etc/
	${INSTALL_DATA} ${WRKSRC}/etc/easymenu.conf-sample \
		${DESTDIR}${PREFIX}/share/easymenu/etc/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo.1 \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo.2 \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/demo.3 \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/main \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/post-demo \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/
	${INSTALL_DATA} ${WRKSRC}/etc/menus-sample/pre-demo \
		${DESTDIR}${PREFIX}/share/easymenu/etc/menus-sample/

.include "../../mk/bsd.pkg.mk"
