# $NetBSD: Makefile,v 1.12 2000/05/22 00:49:52 hubertf Exp $
#

DISTNAME=	vfu-3.00
CATEGORIES=	misc
MASTER_SITES=	http://www.biscom.net/~cade/away/vfu/ \
		ftp://metalab.unc.edu/pub/Linux/utils/file/managers/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/away/vfu/

DEPENDS=	ncurses>=5.0:../../devel/ncurses

USE_PERL5=	yes

do-build:
	cd ${WRKSRC} ; \
	 ${SETENV} ${MAKE_ENV} ${SH} build.netbsd

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} vfu/vfu ftparc/ftparc ${PREFIX}/bin
	for i in rx_auto rx_deb rx_ftp rx_tar rx_zip ; do \
		echo $$i ; \
		${SED} 's,/usr/bin/perl,${LOCALBASE}/bin/perl,' <${WRKSRC}/rx/$$i >${WRKSRC}/rx/$$i.new ; \
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
