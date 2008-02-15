# $NetBSD: Makefile,v 1.43 2008/02/15 16:23:09 gdt Exp $

PKGNAME=		amanda-server-${VERS}
SVR4_PKGNAME=		amase

COMMENT=		Server part of Amanda, a network backup system

USE_TOOLS+=		awk:run perl:run

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

# post-install:
# 	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amanda
# 	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/amanda
# 	for i in ${WRKDIR}/${DISTNAME}/docs/* ; do \
# 		${INSTALL_DATA} $$i ${PREFIX}/share/doc/amanda; \
# 	done
# 	for i in ${WRKDIR}/${DISTNAME}/example/8.5x11.ps \
# 	    ${WRKDIR}/${DISTNAME}/example/DIN-A4.ps \
# 	    ${WRKDIR}/${DISTNAME}/example/DLT.ps \
# 	    ${WRKDIR}/${DISTNAME}/example/EXB-8500.ps \
# 	    ${WRKDIR}/${DISTNAME}/example/HP-DAT.ps \
# 	    ${WRKDIR}/${DISTNAME}/example/amanda.conf \
# 	    ${WRKDIR}/${DISTNAME}/example/chg-multi.conf \
# 	    ${WRKDIR}/${DISTNAME}/example/chg-scsi.conf \
# 	    ${WRKDIR}/${DISTNAME}/example/config.site \
# 	    ${WRKDIR}/${DISTNAME}/example/disklist; do \
# 		${INSTALL_DATA} $$i ${PREFIX}/share/examples/amanda; \
# 	done

.if ${OPSYS} == "SunOS"
PLIST_SRC=	${WRKDIR}/PLIST-src

pre-install:
	${SED} -e 's|^libexec/chg-scsi$$|@comment libexec/chg-scsi needs headers...|' ${PKGDIR}/PLIST > ${PLIST_SRC}
.endif

.include "../../sysutils/amanda-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
