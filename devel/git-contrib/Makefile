# $NetBSD: Makefile,v 1.7 2025/01/13 14:24:44 adam Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	git-contrib-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (contrib)

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

BUILD_DIRS=	contrib/subtree

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	XMLTO_EXTRA=--skip-validation

INSTALL_TARGET=	install install-man

pre-build:
	cd ${WRKSRC}/Documentation && \
	env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} asciidoc.conf

.include "../../mk/bsd.pkg.mk"
