# $NetBSD: Makefile,v 1.35 2004/04/27 04:59:42 snj Exp $
# FreeBSD Id: Makefile,v 1.4 1996/11/18 10:22:47 asami Exp
#

DISTNAME=	id-utils-3.2
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=id-utils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html
COMMENT=	Classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	sh-utils>=2.0nb2

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=	id-utils.info
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.ifdef USE_XEMACS
EMACS=			${LOCALBASE}/bin/xemacs
BUILD_DEPENDS+=		xemacs-[0-9]*:../../editors/xemacs
BUILD_DEPENDS+=		xemacs-packages-[0-9]*:../../editors/xemacs-packages
.elifdef USE_EMACS
EMACS=			${LOCALBASE}/bin/emacs
BUILD_DEPENDS+=		emacs-[0-9]*:../../editors/emacs
.endif

# install byte-compiled file here whenever we use emacs or xemacs...
.if defined(USE_EMACS) || defined(USE_XEMACS)
# we end-up installing .el file there whenever we use emacs or xemacs
LISPDIR?=		share/emacs/site-lisp
CLISPDIR=		${LISPDIR}
.else
# ...or don't install it at all
LISPDIR?=		'@comment '
CLISPDIR?=		'@comment '
.endif
# if not already, set this to the *full* pathname to false command
# so configure won't search further for emacs
EMACS?=			${FALSE:S|^false$|/usr/bin/false|}

CONFIGURE_ENV+=		EMACS=${EMACS}
BUILD_DEFS+=		EMACS
MAKE_ENV+=		BSD_SETENV=${SETENV}

PLIST_SUBST+=		LISPDIR=${LISPDIR}
PLIST_SUBST+=		CLISPDIR=${CLISPDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
