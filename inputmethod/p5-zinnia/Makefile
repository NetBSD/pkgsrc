# $NetBSD: Makefile,v 1.16 2023/07/06 09:40:41 wiz Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14

COMMENT=	Zinnia perl module

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/zinnia/.packlist

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
