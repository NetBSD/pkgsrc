# $NetBSD: Makefile,v 1.9 2004/11/27 16:12:57 taca Exp $

DISTNAME=	ruby-GD-${VER}-1
PKGNAME=	${RUBY_PKGPREFIX}-gd-${VER}.1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://tam.0xfa.com/ruby-gd/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	# not available
COMMENT=	Ruby extension to drive the GD library

USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/ruby-GD-${VER}
VER=			0.7.4

CONFIGURE_ARGS+=	--with-gd-dir=${PREFIX}
CONFIGURE_ARGS+=	--with-ttf
CONFIGURE_ARGS+=	--with-ttf-dir=${PREFIX}
CONFIGURE_ARGS+=	--with-freetype
CONFIGURE_ARGS+=	--with-freetype-dir=${PREFIX}
CONFIGURE_ARGS+=	--enable-gd2_0

post-install:
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/gd
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/gd

.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
