# $NetBSD: Makefile,v 1.7 2004/06/20 21:52:08 xtraeme Exp $

DISTNAME=	ruby-GD-${VER}-1
PKGNAME=	ruby-gd-${VER}.1
PKGREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://tam.0xfa.com/ruby-gd/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	# not available
COMMENT=	Ruby extension to drive the GD library

WRKSRC=		${WRKDIR}/ruby-GD-${VER}
USE_BUILDLINK3=	yes

VER=		0.7.4
DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF=	yes

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
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
