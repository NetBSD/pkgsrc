# $NetBSD: Makefile,v 1.20 2001/05/09 15:08:00 agc Exp $
#

DISTNAME=	vfu-3.01
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/file/managers/} \
		http://www.biscom.net/~cade/away/vfu/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/away/vfu/
COMMENT=	Small, handy, easy-to-use file manager

USE_CURSES=	# defined
REPLACE_NCURSES=	${WRKSRC}/vfu/makefile ${WRKSRC}/vslib/unicon.h \
			${WRKSRC}/vslib/makefile
USE_PERL5=	# defined

do-build:
	cd ${WRKSRC} ; \
	 ${SETENV} ${MAKE_ENV} ${SH} build.netbsd

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} vfu/vfu ftparc/ftparc ${PREFIX}/bin
	for i in rx_auto rx_deb rx_ftp rx_tar rx_zip ; do \
		${ECHO} $$i ; \
		${SED} 's,/usr/bin/perl,${PERL5},' \
			<${WRKSRC}/rx/$$i >${WRKSRC}/rx/$$i.new ; \
		${INSTALL_SCRIPT} ${WRKSRC}/rx/$$i.new ${PREFIX}/bin/$$i ; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/COPYING \
		${WRKSRC}/INSTALL \
		${WRKSRC}/vfu/README \
		${WRKSRC}/VFU.txt \
		${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/vfu.conf \
		${PREFIX}/share/doc/vfu/vfurc.example
	[ -f ${PREFIX}/etc/vfurc ] || \
		${INSTALL_DATA} \
		 ${PREFIX}/share/doc/vfu/vfurc.example ${PREFIX}/etc/vfurc

.include "../../mk/bsd.pkg.mk"
