# $NetBSD: Makefile,v 1.4 2004/04/26 22:07:06 snj Exp $
#

DISTNAME=		bbdb-2.34
CATEGORIES=		mail misc news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bbdb/}

MAINTAINER=		minoura@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/bbdb/
COMMENT=		Insidious Big Brother DataBase, a rolodex-like database Emacs program

# bbdb is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20
CONFLICTS+=		xemacs-packages

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
ALL_TARGET=		all mhe
USE_MAKEINFO=		yes
INFO_FILES=		bbdb.info
INFO_DIR=		${INFODIR}
PLIST_SUBST+=		INFODIR=${INFODIR}

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-emacs=xemacs
CONFIGURE_ARGS+=	--with-package-dir=${PREFIX}/lib/xemacs/site-packages
INSTALL_TARGET=		install-pkg
INFODIR=		lib/xemacs/site-packages/info
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${INFODIR}
.else
LISPDIR=	${EMACS_LISPPREFIX}/bbdb
INFODIR=	info
do-install:
	${MKDIR} ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.elc ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/texinfo/bbdb.info* ${PREFIX}/${INFO_DIR}
.endif

.include "../../mk/bsd.pkg.mk"
