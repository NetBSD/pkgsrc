# $NetBSD: Makefile,v 1.4 2023/12/30 01:21:25 zafer Exp $

DISTNAME=	cobol-mode.el
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}-0.0.20150505
PKGREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	https://www.emacswiki.org/emacs/download/
EXTRACT_SUFX=	# empty

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.emacswiki.org/emacs/CobolMode
COMMENT=	Emacs mode for editing COBOL source code
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/cobol-mode

do-install:
	${INSTALL_DATA} ${WRKSRC}/cobol-mode.el \
		${DESTDIR}${EMACS_LISPPREFIX}/cobol-mode

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
