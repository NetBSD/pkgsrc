# $NetBSD: Makefile,v 1.18 2006/02/05 23:09:39 joerg Exp $

DISTNAME=	ruby-GD-${VER}-1
PKGNAME=	${RUBY_PKGPREFIX}-gd-${VER}.1
PKGREVISION=	5
CATEGORIES=	graphics ruby
MASTER_SITES=	http://raa.ruby-lang.org/cache/ruby-gd/ \
		http://tam.0xfa.com/ruby-gd/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Ruby extension to drive the GD library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/ruby-GD-${VER}
VER=			0.7.4

CONFIGURE_ARGS+=	--with-gd-dir=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-ttf
CONFIGURE_ARGS+=	--with-ttf-dir=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-freetype
CONFIGURE_ARGS+=	--with-freetype-dir=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-gd2_0

post-install:
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/gd
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/gd

.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
