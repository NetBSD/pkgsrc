# $NetBSD: Makefile,v 1.17 2001/01/07 14:34:39 wiz Exp $
#

DISTNAME=	vfu-3.01
CATEGORIES=	misc
MASTER_SITES=	http://www.biscom.net/~cade/away/vfu/ \
		ftp://metalab.unc.edu/pub/Linux/utils/file/managers/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/away/vfu/

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
