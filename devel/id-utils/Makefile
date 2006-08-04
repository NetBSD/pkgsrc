# $NetBSD: Makefile,v 1.47 2006/08/04 19:23:39 christos Exp $

DISTNAME=	idutils-4.1
#PKGREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=idutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html
COMMENT=	Classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	sh-utils>=2.0nb2 coreutils-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_EMACS=no
INFO_FILES=		# PLIST
MAKE_ENV+=		BSD_SETENV=${SETENV:Q}

# Don't byte-compile the .el file.
MAKE_FLAGS+=		elc_SCRIPTS=

LISPDIR=		${PREFIX}/share/emacs/site-lisp
REQD_DIRS=		${LISPDIR}

.include "../../devel/gettext-lib/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/idutils.el ${LISPDIR}

.include "../../mk/bsd.pkg.mk"
