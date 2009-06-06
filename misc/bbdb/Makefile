# $NetBSD: Makefile,v 1.20 2009/06/06 15:32:56 minskim Exp $
#

DISTNAME=		bbdb-2.34
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		3
CATEGORIES=		mail misc news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bbdb/}

MAINTAINER=		minoura@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/bbdb/
COMMENT=		Insidious Big Brother DataBase, a rolodex-like database Emacs program

# bbdb is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=	emacs23 emacs22 emacs22nox emacs21 emacs21nox \
				emacs20 emacs20nox
CONFLICTS+=		xemacs-packages-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		all mhe
USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST
LISPDIR=		${EMACS_LISPPREFIX}/bbdb
INSTALLATION_DIRS=	${EMACS_INFOPREFIX}

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-emacs=xemacs
CONFIGURE_ARGS+=	--with-package-dir=${PREFIX}/lib/xemacs/site-packages
INSTALL_TARGET=		install-pkg
.else
do-install:
	${MKDIR} ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.elc ${DESTDIR}${LISPDIR}
	cd ${WRKSRC}/texinfo; for f in bbdb.info bbdb.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done
.endif

.include "../../mk/bsd.pkg.mk"
