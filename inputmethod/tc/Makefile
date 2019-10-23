# $NetBSD: Makefile,v 1.20 2019/10/23 14:01:59 mef Exp $
#

DISTNAME=	tc-2.3.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/tcode/resources/soft/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/tcode/tc2/index.html
COMMENT=	T-Code driver for Emacs
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no
SUBST_CLASSES+=	string-to-int
SUBST_STAGE.string-to-int=	pre-configure
SUBST_FILES.string-to-int=	 \
	lisp/eelll.el	\
	lisp/tc-is19.el	\
	lisp/tc-is20.el	\
	lisp/tc-pre-base	\
	lisp/tc-pre-base.in	\
	lisp/tc-pre.el
SUBST_SED.string-to-int=	-e 's/string-to-int/string-to-number/'

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=--with-emacs=xemacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/tc
.endif

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
