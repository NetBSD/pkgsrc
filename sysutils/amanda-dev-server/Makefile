# $NetBSD: Makefile,v 1.1.1.1 2002/05/02 13:28:16 bouyer Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

PKGNAME=		amanda-server-${VERS}

COMMENT=		Server part of Amanda, a network backup system

DEPENDS+=		amanda-common-${VERS}:../../sysutils/amanda-dev-common

USE_PERL5=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-dev-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=         ac_cv_lib_intl_main=no
CONFIGURE_ENV+=         ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=         ac_cv_lib_readline_readline=no

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

.include "../../mk/bsd.pkg.mk"
