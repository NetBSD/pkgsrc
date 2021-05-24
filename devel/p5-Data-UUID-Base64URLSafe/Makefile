# $NetBSD: Makefile,v 1.7 2021/05/24 19:50:28 wiz Exp $

DISTNAME=	Data-UUID-Base64URLSafe-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

HOMEPAGE=	https://metacpan.org/release/Data-UUID-Base64URLSafe
COMMENT=	URL-safe UUIDs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Data/UUID/Base64URLSafe/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
