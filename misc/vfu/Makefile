# $NetBSD: Makefile,v 1.22 2001/06/20 05:29:22 jlam Exp $
#

DISTNAME=	vfu-3.01
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/file/managers/} \
		http://www.biscom.net/~cade/away/vfu/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/away/vfu/
COMMENT=	Small, handy, easy-to-use file manager

USE_BUILDLINK_ONLY=	# defined
USE_PERL5=		# defined

DOCDIR=			${PREFIX}/share/doc/vfu
EGDIR=			${PREFIX}/share/examples/vfu

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${SH} build.netbsd

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} vfu/vfu ftparc/ftparc ${PREFIX}/bin
	cd ${WRKSRC}; for i in rx_auto rx_deb rx_ftp rx_tar rx_zip; do	\
		${ECHO} $$i;						\
		${SED} -e "s|/usr/bin/perl|${PERL5}|g"			\
			rx/$$i > rx/$$i.new;				\
		${INSTALL_SCRIPT} rx/$$i.new ${PREFIX}/bin/$$i;		\
	done
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	cd ${WRKSRC};							\
	${INSTALL_DATA} COPYING INSTALL vfu/README VFU.txt ${DOCDIR}
	cd ${WRKSRC};							\
	${INSTALL_DATA} ${WRKSRC}/vfu.conf ${EGDIR}/vfurc

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
