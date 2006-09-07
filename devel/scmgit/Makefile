# $NetBSD: Makefile,v 1.3 2006/09/07 22:21:06 rillig Exp $
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
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

MAKE_ENV+=	DESTDIR=""
MAKE_ENV+=	HOME=${PREFIX:Q}
USE_TOOLS+=	gmake perl:run sh:run
EXTRACT_USING=	gtar

MAKE_ENV+=	PERL_PATH=${PERL5:Q}
MAKE_ENV+=	PYTHON_PATH=${PYTHONBIN:Q}
MAKE_ENV+=	SHELL_PATH=${SH:Q}
BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../lang/python/application.mk"

NEEDS_SUBPROCESS_PY!= \
	if ok=`${PYTHONBIN} -c 'import subprocess; print "OK"' 2>/dev/null` \
	&& ${TEST} "$$ok" = "OK"; then echo "no"; else echo "yes"; fi
.if ${NEEDS_SUBPROCESS_PY} == "yes"
PLIST_SUBST+=	IF_NEEDS_SUBPROCESS_PY=""
.else
PLIST_SUBST+=	IF_NEEDS_SUBPROCESS_PY="@comment "
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
