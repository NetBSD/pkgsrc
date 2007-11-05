# $NetBSD: Makefile,v 1.19 2007/11/05 06:34:55 bjs Exp $
#

DISTNAME=	git-1.5.3.5
PKGNAME=	scm${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://git.or.cz/
COMMENT=	Tree History Storage Tool

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	git-[0-9]*		# misc/git
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

MAKE_ENV+=	HOME=${PREFIX:Q}
USE_LANGUAGES=	c99
USE_TOOLS+=	gmake perl:run sh:run wish:run tar
EXTRACT_USING=	gtar

MAKE_ENV+=	CURLDIR=${BUILDLINK_PREFIX.curl:Q}
MAKE_ENV+=	PERL_PATH=${PERL5:Q}
MAKE_ENV+=	PYTHON_PATH=${PYTHONBIN:Q}
MAKE_ENV+=	SHELL_PATH=${SH:Q}
MAKE_ENV+=	TAR=${TAR:Q}
BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
LDFLAGS=	${COMPILER_RPATH_FLAG}${PREFIX}/lib
LIBS.SunOS+=	-liconv
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

PERL5_PACKLIST=	auto/Git/.packlist
PERL5_CONFIGURE_DIRS=	${WRKSRC}/perl

.include "../../mk/bsd.prefs.mk"

###
### XXX Do all the BSDs fit this category?
###
.if ${OPSYS} == "NetBSD"
.  include "../../converters/libiconv/builtin.mk"
.  if ${ICONV_TYPE} == "native"
CFLAGS+=	-DOLD_ICONV
.  endif
.endif

.include "../../lang/python/application.mk"

NEEDS_SUBPROCESS_PY!= \
	if ok=`${PYTHONBIN} -c 'import subprocess; print "OK"' 2>/dev/null` \
	&& ${TEST} "$$ok" = "OK"; then echo "no"; else echo "yes"; fi
.if ${NEEDS_SUBPROCESS_PY} == "yes"
PLIST_SUBST+=	IF_NEEDS_SUBPROCESS_PY=""
.else
PLIST_SUBST+=	IF_NEEDS_SUBPROCESS_PY="@comment "
.endif

#.include "../../mk/emacs.mk" # XXX TODO (see patch-ad)

post-install:
	chmod 644 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/git*.1
	chmod 644 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/git*.7

.include "../../lang/perl5/module.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
