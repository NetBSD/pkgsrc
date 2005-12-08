# $NetBSD: Makefile,v 1.41 2005/12/08 09:03:50 rillig Exp $

DISTNAME=	id-utils-3.2
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=id-utils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html
COMMENT=	Classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	sh-utils>=2.0nb2

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes

INFO_FILES=	id-utils.info
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
EMACS=			${LOCALBASE}/bin/xemacs
BUILD_DEPENDS+=		xemacs-[0-9]*:../../editors/xemacs
BUILD_DEPENDS+=		xemacs-packages-[0-9]*:../../editors/xemacs-packages
.elif defined(USE_EMACS)
EMACS=			${LOCALBASE}/bin/emacs
BUILD_DEPENDS+=		emacs-[0-9]*:../../editors/emacs
.endif

# install byte-compiled file here whenever we use emacs or xemacs...
.if defined(USE_EMACS) || defined(USE_XEMACS)
# we end-up installing .el file there whenever we use emacs or xemacs
PLIST_SUBST+=		LISPDIR=share/emacs/site-lisp
PLIST_SUBST+=		CLISPDIR=share/emacs/site-lisp
.else
# ...or don't install it at all
PLIST_SUBST+=		LISPDIR='@comment '
PLIST_SUBST+=		CLISPDIR='@comment '
.endif
# if not already, set this to the *full* pathname to false command
# so configure won't search further for emacs
EMACS?=			${FALSE:S|^false$|/usr/bin/false|}

CONFIGURE_ENV+=		EMACS=${EMACS:Q}
BUILD_DEFS+=		EMACS
MAKE_ENV+=		BSD_SETENV=${SETENV:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
