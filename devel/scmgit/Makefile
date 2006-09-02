# $NetBSD: Makefile,v 1.1.1.1 2006/09/02 17:11:07 rillig Exp $
#

DISTNAME=	git-1.4.1
PKGNAME=	scm${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://git.or.cz/
COMMENT=	Tree History Storage Tool

CONFLICTS+=	git-[0-9]*		# misc/git
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

MAKE_ENV+=	DESTDIR=""
MAKE_ENV+=	HOME=${PREFIX:Q}
USE_TOOLS+=	gmake perl:run sh:run
EXTRACT_USING=	gtar

MAKE_ENV+=	PERL_PATH=${PERL5:Q}
MAKE_ENV+=	PYTHON_PATH=${PYTHONBIN:Q}
MAKE_ENV+=	SHELL_PATH=${SH:Q}
BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
