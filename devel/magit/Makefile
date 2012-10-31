# $NetBSD: Makefile,v 1.2 2012/10/31 11:17:27 asau Exp $
#

DISTNAME=	magit-1.2.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/downloads/magit/magit/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://magit.github.com/magit/
COMMENT=	Inspect and modify Git repositories from Emacs
LICENSE=	gnu-gpl-v3

FETCH_USING=		curl
INFO_FILES=		yes
USE_LANGUAGES=		# none
USE_TOOLS=		gmake makeinfo
NO_CONFIGURE=		yes

MAKE_FLAGS+=		EMACS=${EMACS_BIN}
MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALL_TARGET=		install_core

INSTALLATION_DIRS=	${EMACS_LISPPREFIX} ${PKGINFODIR}

EMACS_MODULES=		base

.include "../../editors/emacs/modules.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/magit.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/

.include "../../mk/bsd.pkg.mk"
