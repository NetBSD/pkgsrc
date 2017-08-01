# $NetBSD: Makefile,v 1.31 2017/08/01 14:59:02 wiz Exp $
#

DISTNAME=		bbdb-2.35
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail misc news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bbdb/}

MAINTAINER=		minoura@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/bbdb/
COMMENT=		Insidious Big Brother DataBase, a rolodex-like database Emacs program

# bbdb is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=	emacs25 \
				emacs24 emacs24nox emacs23 emacs23nox \
				emacs22 emacs22nox emacs21 emacs21nox \

CONFLICTS+=		xemacs-packages-[0-9]*

USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--enable-rmail
GNU_CONFIGURE=		yes
BUILD_TARGET=		all mhe
USE_TOOLS+=		makeinfo
INFO_FILES=		yes
LISPDIR=		${EMACS_LISPPREFIX}/bbdb
INSTALLATION_DIRS=	${EMACS_INFOPREFIX}
MAKE_JOBS_SAFE=		no

.include "../../editors/emacs/modules.mk"

post-extract:
	${RM} -rf ${WRKSRC}/lisp/*.elc

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
