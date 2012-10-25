# $NetBSD: Makefile,v 1.8 2012/10/25 06:56:08 asau Exp $

.include "../../textproc/migemo/Makefile.common"

PKGNAME=		${RUBY_PKGPREFIX}-migemo-${MIGEMO_VERSION}
PKGREVISION=		1

COMMENT=		Japanese text search tool/library

LICENSE=        gnu-gpl-v2

DEPENDS+=		${RUBY_PKGPREFIX}-bsearch-[0-9]*:../../devel/ruby-bsearch
DEPENDS+=		${RUBY_PKGPREFIX}-romkan-[0-9]*:../../converters/ruby-romkan

USE_TOOLS+=		autoconf automake aclocal
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}
MAKE_ENV+=		RUBYOPT=-Ke

REPLACE_RUBY=		migemo migemo-client migemo-grep migemo-server

pre-configure:
	cd ${WRKSRC} && aclocal && automake -a --foreign -i && autoconf

TEST_TARGET=		check

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
