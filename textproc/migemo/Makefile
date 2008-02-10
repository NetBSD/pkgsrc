# $NetBSD: Makefile,v 1.1.1.1 2008/02/10 13:08:51 obache Exp $

.include "../../textproc/migemo/Makefile.common"

PKGNAME=		${RUBY_PKGPREFIX}-migemo-${MIGEMO_VERSION}

COMMENT=		Japanese text search tool/library

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${RUBY_PKGPREFIX}-bsearch-*:../../devel/ruby-bsearch
DEPENDS+=		${RUBY_PKGPREFIX}-romkan-*:../../converters/ruby-romkan

USE_TOOLS+=		autoconf213 automake14 aclocal
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-rubydir=${RUBY_SITELIBDIR}

REPLACE_RUBY=		migemo migemo-client migemo-grep migemo-server

pre-configure:
	cd ${WRKSRC} && aclocal && automake -a --foreign -i && autoconf

TEST_TARGET=		check

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
