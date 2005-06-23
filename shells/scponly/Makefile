# $NetBSD: Makefile,v 1.3 2005/06/23 16:43:00 kristerw Exp $

DISTNAME=	scponly-4.0
PKGREVISION=	1
CATEGORIES=	shells security
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.sublimation.org/scponly/
COMMENT=	Tiny shell that only permits scp and sftp

GNU_CONFIGURE=	yes

USE_TOOLS+=		chgrp chmod chown echo ln ls mkdir mv pwd rm rmdir
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_CHGRP="${TOOLS_CHGRP}"
CONFIGURE_ENV+=		ac_cv_path_PROG_CHMOD="${TOOLS_CHMOD}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_CHMOD="${TOOLS_CHMOD}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_CHOWN="${TOOLS_CHOWN}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_ECHO="${TOOLS_ECHO}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_LN="${TOOLS_LN}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_LS="${TOOLS_LS}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_MKDIR="${TOOLS_MKDIR}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_MV="${TOOLS_MV}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_PWD="${TOOLS_PWD_CMD}"
CONFIGURE_ENV+=		ac_cv_path_PROG_RM="${TOOLS_RM}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_RM="${TOOLS_RM}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_RMDIR="${TOOLS_RMDIR}"
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_PKGINSTALL=		yes
PKG_SHELL=		${PREFIX}/bin/scponly
PKG_SYSCONFSUBDIR=	scponly

EGDIR=		${PREFIX}/share/examples/scponly
CONF_FILES=	${EGDIR}/debuglevel ${PKG_SYSCONFDIR}/debuglevel

.include "../../mk/bsd.pkg.mk"
