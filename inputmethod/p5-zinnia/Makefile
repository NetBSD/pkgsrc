# $NetBSD: Makefile,v 1.4 2012/10/03 21:56:17 wiz Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3

COMMENT=	Zinnia perl module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/zinnia/.packlist

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
