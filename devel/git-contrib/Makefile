# $NetBSD: Makefile,v 1.2 2015/07/10 17:51:02 khorben Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	git-contrib-${GIT_VERSION}
PKGREVISION=1
COMMENT=	GIT Tree History Storage Tool (contrib)

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

BUILD_DIRS=	contrib/subtree

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}

INSTALL_TARGET=	install install-man

.include "../../mk/bsd.pkg.mk"
