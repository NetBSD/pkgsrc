# $NetBSD: Makefile,v 1.11 2010/04/09 01:36:34 obache Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
CATEGORIES=	multimedia
MASTER_SITES=	http://rubyforge.org/frs/download.php/44137/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mingruby.rubyforge.org/
COMMENT=	Ruby extension to drive the Ming SWF library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pax
USE_RUBY_SETUP=		yes
VER=			0.2.1

WRKSRC=			${WRKDIR}/ming-ruby

REPLACE_RUBY_DIRS=	${WRKSRC}/examples

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE}
CONFIGURE_ARGS+=	--siterubyver=${PREFIX}/${RUBY_VENDORLIB}
CONFIGURE_ARGS+=	--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

post-install:
		${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/ming
		cd ${WRKSRC}/examples && \
			pax -wrppm '-s|.*/CVS.*$$||' . ${DESTDIR}${RUBY_EXAMPLESDIR}/ming

.include "../../multimedia/ming/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
