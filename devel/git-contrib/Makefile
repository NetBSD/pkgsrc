# $NetBSD: Makefile,v 1.4 2023/02/04 09:27:15 kim Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	git-contrib-${GIT_VERSION}
PKGREVISION=	1
COMMENT=	GIT Tree History Storage Tool (contrib)

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

BUILD_DIRS=	contrib/subtree

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	XMLTO_EXTRA=--skip-validation

INSTALL_TARGET=	install install-man

.include "../../mk/bsd.pkg.mk"
