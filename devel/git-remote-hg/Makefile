# $NetBSD: Makefile,v 1.8 2023/08/14 05:24:08 wiz Exp $

DISTNAME=	git-remote-hg-0.6
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GITHUB:=felipec/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://felipec.wordpress.com/2012/11/13/git-remote-hg-bzr-2/
COMMENT=	Bridge support in git for mercurial
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor
DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_TOOLS+=	gmake
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}/man1
REPLACE_PYTHON=	git-remote-hg

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALL_TARGET=	install install-doc

post-extract:
	${MKDIR} ${BUILDLINK_DIR}/bin && \
		${LN} -fs ${PREFIX}/bin/asciidoctor${RUBY_SUFFIX} ${BUILDLINK_DIR}/bin/asciidoctor

.include "../../lang/python/application.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
