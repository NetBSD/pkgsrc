# $NetBSD: Makefile,v 1.27 2026/09/25 09:48:10 wiz Exp $

DISTNAME=	tc-2.3.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://openlab.ring.gr.jp/tcode/resources/soft/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/tcode/tc2/index.html
COMMENT=	T-Code driver for Emacs
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=			no
SUBST_CLASSES+=			string-to-int
SUBST_STAGE.string-to-int=	pre-configure
SUBST_FILES.string-to-int=	\
	lisp/eelll.el	\
	lisp/tc-is19.el	\
	lisp/tc-is20.el	\
	lisp/tc-pre-base	\
	lisp/tc-pre-base.in	\
	lisp/tc-pre.el
SUBST_SED.string-to-int=	-e 's/string-to-int/string-to-number/'

EMACS_VERSIONS_ACCEPTED=	emacs29 emacs29nox

.include "../../editors/emacs/modules.mk"

CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/tc
.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-emacs=xemacs
.endif

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
