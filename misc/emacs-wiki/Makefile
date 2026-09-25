# $NetBSD: Makefile,v 1.10 2026/09/25 09:48:11 wiz Exp $
#

DISTNAME=	${EMACSWIKI}-${EMACSWIKIVERSION}
PKGNAME=	emacs-wiki-${EMACSWIKIVERSION}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.mwolson.org/static/dist/emacs-wiki/
#EXTRACT_SUFX=	.gz

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://repose.cx/emacs/wiki/
COMMENT=	Wiki major mode for emacs, which aims for implicit and natural markup
LICENSE=	gnu-gpl-v2

EMACSWIKI=		emacs-wiki
EMACSWIKIVERSION=	2.72
DEPENDS=		${EMACS_PKGNAME_PREFIX}semi>=1.14.6:../../devel/semi

USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	ELISPDIR=${DESTDIR}${EMACS_LISPPREFIX}/emacs-wiki

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
