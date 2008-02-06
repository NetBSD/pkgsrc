# $NetBSD: Makefile,v 1.3 2008/02/06 07:53:31 bjs Exp $
#

.include "${.CURDIR}/../scmgit/Makefile.common"

PKGNAME=		scmgit-base-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (base package)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		git-[0-9]*		# misc/git

USE_LANGUAGES=		c99
USE_TOOLS+=		perl:run sh:run wish:run msgfmt

MAKE_ENV+=		CURLDIR=${BUILDLINK_PREFIX.curl:Q}
MAKE_ENV+=		PYTHON_PATH=${PYTHONBIN:Q}

BUILD_TARGET=		all
INSTALL_TARGET=		install

PERL5_PACKLIST=		auto/Git/.packlist
PERL5_CONFIGURE_DIRS=	${WRKSRC}/perl

.include "../../mk/bsd.fast.prefs.mk"
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

## XXX Do all the BSDs fit this category?
#
.if ${OPSYS} == "NetBSD"
CHECK_BUILTIN.iconv:=yes
.  include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=no
.  if ${ICONV_TYPE} == "native"
CFLAGS+=	-DOLD_ICONV
.  endif
.endif

.include "../../lang/perl5/module.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
