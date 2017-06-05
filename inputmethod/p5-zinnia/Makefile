# $NetBSD: Makefile,v 1.10 2017/06/05 14:24:02 ryoon Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8

COMMENT=	Zinnia perl module

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/zinnia/.packlist

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
