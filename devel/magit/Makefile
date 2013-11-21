# $NetBSD: Makefile,v 1.7 2013/11/21 23:50:04 jmmv Exp $
#

DISTNAME=	magit-1.2.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/magit/magit/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://magit.github.com/magit/
COMMENT=	Inspect and modify Git repositories from Emacs
LICENSE=	gnu-gpl-v3

FETCH_USING=		curl
INFO_FILES=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		gmake makeinfo
NO_CONFIGURE=		yes

MAKE_FLAGS+=		EMACS=${EMACS_BIN}
MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		SYSCONFDIR=${PKG_SYSCONFDIR}

# pbulk sets BATCH=1 on the make command line, which breaks the makefile.
SUBST_CLASSES+=		batch
SUBST_STAGE.batch=	pre-build
SUBST_FILES.batch=	Makefile Makefile-e
SUBST_SED.batch+=	-e 's,BATCH,BAATCH,'
SUBST_MESSAGE.batch=	Working around pbulk make variable pollution.

INSTALL_TARGET=		install_core

INSTALLATION_DIRS=	${EMACS_LISPPREFIX} ${PKGINFODIR}

EMACS_MODULES=		base

.include "../../editors/emacs/modules.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/magit.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/

.include "../../mk/bsd.pkg.mk"
