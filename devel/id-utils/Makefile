# $NetBSD: Makefile,v 1.45 2006/04/08 21:20:06 jlam Exp $

DISTNAME=	id-utils-3.2
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=id-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html
COMMENT=	Classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	sh-utils>=2.0nb2 coreutils-[0-9]*

BUILD_USES_MSGFMT=	yes
USE_PKGLOCALEDIR=	yes

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
	${INSTALL_DATA} ${WRKSRC}/lisp/id-utils.el ${LISPDIR}

.include "../../mk/bsd.pkg.mk"
