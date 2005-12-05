# $NetBSD: Makefile,v 1.7 2005/12/05 03:04:28 snj Exp $

DISTNAME=	scponly-4.1
CATEGORIES=	shells security
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.sublimation.org/scponly/
COMMENT=	Tiny shell that only permits scp and sftp

GNU_CONFIGURE=	yes

USE_TOOLS+=		chgrp chmod chown echo id ln ls mkdir mv pwd rm rmdir
CONFIGURE_ENV+=		scponly_PROG_CHGRP="${TOOLS_CHGRP}"
CONFIGURE_ENV+=		PROG_CHMOD="${TOOLS_CHMOD}"
CONFIGURE_ENV+=		scponly_PROG_CHMOD="${TOOLS_CHMOD}"
CONFIGURE_ENV+=		PROG_CHOWN="${TOOLS_CHOWN}"
CONFIGURE_ENV+=		scponly_PROG_CHOWN="${TOOLS_CHOWN}"
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_ECHO="${TOOLS_ECHO}"
CONFIGURE_ENV+=		scponly_PROG_ID="${TOOLS_ID}"
CONFIGURE_ENV+=		scponly_PROG_LN="${TOOLS_LN}"
CONFIGURE_ENV+=		scponly_PROG_LS="${TOOLS_LS}"
CONFIGURE_ENV+=		scponly_PROG_MKDIR="${TOOLS_MKDIR}"
CONFIGURE_ENV+=		scponly_PROG_MV="${TOOLS_MV}"
CONFIGURE_ENV+=		scponly_PROG_PWD="${TOOLS_PWD_CMD}"
CONFIGURE_ENV+=		PROG_RM="${TOOLS_RM}"
CONFIGURE_ENV+=		scponly_PROG_RM="${TOOLS_RM}"
CONFIGURE_ENV+=		scponly_PROG_RMDIR="${TOOLS_RMDIR}"
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_PKGINSTALL=		yes
PKG_SHELL=		bin/scponly
PKG_SYSCONFSUBDIR=	scponly

EGDIR=		${PREFIX}/share/examples/scponly
CONF_FILES=	${EGDIR}/debuglevel ${PKG_SYSCONFDIR}/debuglevel

.include "../../mk/bsd.pkg.mk"
