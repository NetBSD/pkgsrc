# $NetBSD: Makefile,v 1.18 2001/10/03 15:28:56 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1996/11/18 10:22:47 asami Exp
#

DISTNAME=	id-utils-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=id-utils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html
COMMENT=	Classic Berkeley gid/lid tools for looking up variables in code

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

BUILD_USES_MSGFMT=	yes
BUILD_USES_GETTEXT_M4=	yes
USE_BUILDLINK_ONLY=	yes

INFO_FILES=	id-utils.info
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.ifdef USE_XEMACS
EMACS=			${LOCALBASE}/bin/xemacs
BUILD_DEPENDS+=		xemacs-[0-9]*:../editors/xemacs
BUILD_DEPENDS+=		xemacs-packages-[0-9]*:../editors/xemacs-packages
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

PLIST_SUBST+=		LISPDIR=${LISPDIR}
PLIST_SUBST+=		CLISPDIR=${CLISPDIR}

post-patch:
	cd ${WRKSRC}/lisp && ${RM} -f elisp-comp

# we manually copy missing and elisp-comp scripts in the sources
# to get around an apparent bug (??) in automake...
pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/aclocal && \
	${LOCALBASE}/bin/autoheader && \
	${CP} ${LOCALBASE}/share/automake/missing ./missing && \
	${CP} ${LOCALBASE}/share/automake/elisp-comp ./lisp/elisp-comp && \
	${LOCALBASE}/bin/automake --gnu && \
	${LOCALBASE}/bin/autoconf

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
