# $NetBSD: Makefile,v 1.31 2023/12/19 12:01:46 zafer Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
PKGREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://mingruby.rubyforge.org/
COMMENT=	Ruby extension to drive the Ming SWF library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pax
USE_RUBY_SETUP=		yes
VER=			0.2.1

WRKSRC=			${WRKDIR}/ming-ruby

REPLACE_RUBY_DIRS=	${WRKSRC}/examples

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE}
CONFIGURE_ARGS+=	--siterubyver=${PREFIX}/${RUBY_VENDORLIB}
CONFIGURE_ARGS+=	--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}
# pass more options to extconf.rb
CONFIGURE_ARGS+=	-- --with-freetype-dir=${BUILDLINK_PREFIX.freetype2}

SUBST_CLASSES+=		giflib
SUBST_STAGE.giflib=	pre-configure
SUBST_FILES.giflib=	ext/ming/mingc/extconf.rb
SUBST_SED.giflib=	-e 's/ungif/gif/g'

INSTALLATION_DIRS+=	${RUBY_EG}/ming

pre-configure:
	${CHMOD} -x ${WRKSRC}/examples/rubyguts/midnightcommander/ruby.syntax \
		${WRKSRC}/examples/rubyguts/railsconnection/index.rhtml

post-install:
	cd ${WRKSRC}/examples && \
		pax -wrppm '-s|.*/CVS.*$$||' . \
			${DESTDIR}${PREFIX}/${RUBY_EG}/ming

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
