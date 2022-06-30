# $NetBSD: Makefile,v 1.5 2022/06/30 11:18:14 nia Exp $

DISTNAME=	git-remote-hg-20140603
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GITHUB:=felipec/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://felipec.wordpress.com/2012/11/13/git-remote-hg-bzr-2/
COMMENT=	Bridge support in git for mercurial
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	git-remote-hg
GITHUB_TAG=	aa528c9649bf0fd8031656f21679c380aedc6b82
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	gmake
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}/man1
REPLACE_PYTHON=	git-remote-hg

INSTALL_TARGET=	install install-doc
AUTO_MKDIRS=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
