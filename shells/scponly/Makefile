# $NetBSD: Makefile,v 1.18 2020/05/20 06:09:08 rillig Exp $

DISTNAME=	scponly-4.8
PKGREVISION=	2
CATEGORIES=	shells security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scponly/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sborrill@NetBSD.org
#HOMEPAGE=	http://sublimation.org/scponly/wiki/
COMMENT=	Shell that only permits sftp

GNU_CONFIGURE=	yes

USE_TOOLS+=		chgrp chmod chown echo id ln ls mkdir mv pwd rm rmdir
CONFIGURE_ENV+=		scponly_PROG_CHGRP=${TOOLS_CHGRP:Q}
CONFIGURE_ENV+=		PROG_CHMOD=${TOOLS_CHMOD:Q}
CONFIGURE_ENV+=		scponly_PROG_CHMOD=${TOOLS_CHMOD:Q}
CONFIGURE_ENV+=		PROG_CHOWN=${TOOLS_CHOWN:Q}
CONFIGURE_ENV+=		scponly_PROG_CHOWN=${TOOLS_CHOWN:Q}
CONFIGURE_ENV+=		ac_cv_path_scponly_PROG_ECHO=${TOOLS_ECHO:Q}
CONFIGURE_ENV+=		scponly_PROG_ID=${TOOLS_ID:Q}
CONFIGURE_ENV+=		scponly_PROG_LN=${TOOLS_LN:Q}
CONFIGURE_ENV+=		scponly_PROG_LS=${TOOLS_LS:Q}
CONFIGURE_ENV+=		scponly_PROG_MKDIR=${TOOLS_MKDIR:Q}
CONFIGURE_ENV+=		scponly_PROG_MV=${TOOLS_MV:Q}
CONFIGURE_ENV+=		scponly_PROG_PWD=${TOOLS_PWD_CMD:Q}
CONFIGURE_ENV+=		PROG_RM=${TOOLS_RM:Q}
CONFIGURE_ENV+=		scponly_PROG_RM=${TOOLS_RM:Q}
CONFIGURE_ENV+=		scponly_PROG_RMDIR=${TOOLS_RMDIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-scp-compat

# helper.c: In function 'mysetenv':
# helper.c:565:14: error: array subscript has type 'char' [-Werror=char-subscripts]
#   if ((safeenv[count] = strdup(buff))) {
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

PKG_SHELL=		bin/scponly
PKG_SYSCONFSUBDIR=	scponly

EGDIR=		${PREFIX}/share/examples/scponly
CONF_FILES=	${EGDIR}/debuglevel ${PKG_SYSCONFDIR}/debuglevel

.include "../../mk/bsd.pkg.mk"
