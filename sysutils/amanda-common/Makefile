# $NetBSD: Makefile,v 1.18 2001/10/18 15:20:39 veego Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.2p2
PKGNAME=		amanda-common-2.4.2p2
SVR4_PKGNAME=		amaco
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Libraries and binaries used by both the client and server parts of amanda

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

.if ${OPSYS} == "NetBSD"
CPPFLAGS=		# empty
.if exists(/usr/sbin/user)
ADDUSER=		/usr/sbin/useradd
ADDGROUP=		/usr/sbin/groupadd
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
.endif
.elif ${OPSYS} == "SunOS"
CPPFLAGS+=		-D_LARGEFILE64_SOURCE
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

CONFIGURE_ARGS+=	--without-server --without-restore --without-client

# Prevent configure script from finding unnecessary libraries.
#
CONFIGURE_ENV+=		ac_cv_lib_intl_main=no
CONFIGURE_ENV+=		ac_cv_lib_termcap_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_readline_readline=no

INSTALL_SUBST+=		AMUSER=${AMANDA_USER}
INSTALL_SUBST+=		AMGROUP=${AMANDA_GROUP}
INSTALL_SUBST+=		AMVAR=${AMANDA_VAR}

INSTALL_SUBST+=		ADDUSER=${ADDUSER:Q}
INSTALL_SUBST+=		ADDGROUP=${ADDGROUP:Q}
INSTALL_SUBST+=		CAT=${CAT:Q}
INSTALL_SUBST+=		CHGRP=${CHGRP:Q}
INSTALL_SUBST+=		CHMOD=${CHMOD:Q}
INSTALL_SUBST+=		CHOWN=${CHOWN:Q}
INSTALL_SUBST+=		ID=${ID:Q}
INSTALL_SUBST+=		MKDIR=${MKDIR:Q}
INSTALL_SUBST+=		RM=${RM:Q}
INSTALL_SUBST+=		RMDIR=${RMDIR:Q}
INSTALL_SUBST+=		TOUCH=${TOUCH:Q}
INSTALL_SUBST+=		TRUE=${TRUE:Q}

INSTALL_SUBST_SED=	${INSTALL_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${INSTALL_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${INSTALL_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
