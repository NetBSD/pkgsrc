# $NetBSD: Makefile,v 1.14 2006/05/19 09:24:31 joerg Exp $
#

DISTNAME=		bbdb-2.34
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		2
CATEGORIES=		mail misc news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bbdb/}

MAINTAINER=		minoura@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/bbdb/
COMMENT=		Insidious Big Brother DataBase, a rolodex-like database Emacs program

# bbdb is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20
CONFLICTS+=		xemacs-packages

BROKEN_IN=		pkgsrc-2006Q1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		all mhe
USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST
LISPDIR=		${EMACS_LISPPREFIX}/bbdb
INSTALLATION_DIRS=	${EMACS_INFOPREFIX}

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-emacs=xemacs
CONFIGURE_ARGS+=	--with-package-dir=${PREFIX}/lib/xemacs/site-packages
INSTALL_TARGET=		install-pkg
.else
do-install:
	${MKDIR} ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.elc ${LISPDIR}
	cd ${WRKSRC}/texinfo; for f in bbdb.info bbdb.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
.endif

.include "../../mk/bsd.pkg.mk"
