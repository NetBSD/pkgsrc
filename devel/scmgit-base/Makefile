# $NetBSD: Makefile,v 1.7.4.1 2008/08/12 10:00:23 tron Exp $
#

.include "${.CURDIR}/../scmgit/Makefile.common"

PKGNAME=		scmgit-base-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (base package)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		git-[0-9]*		# misc/git

DEPENDS+=		p5-Error>=0.17015:../../devel/p5-Error

USE_LANGUAGES=		c99
USE_TOOLS+=		perl:run sh:run msgfmt

CFLAGS.NetBSD+=	 	-D_NETBSD_SOURCE

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl:Q}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat:Q}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv:Q}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib:Q}

BUILD_TARGET=		all
INSTALL_TARGET=		install

PERL5_CONFIGURE= 	no
PERL5_PACKLIST=		auto/Git/.packlist
REPLACE_PERL+=		*.perl */*.perl */*/*.perl

GITCOREDIR=		${PREFIX}/libexec/git-core

CONFIGURE_ENV+=		gitexecdir=${GITCOREDIR:Q}

#.include "../../mk/emacs.mk" # XXX TODO (see patch-ad)

.include "options.mk"
.include "../../lang/perl5/module.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
