# $NetBSD: Makefile,v 1.21 2022/06/28 11:35:18 wiz Exp $

DISTNAME=	X500-DN-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=X500/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/X500-DN
COMMENT=	Handle X.500 DNs (Distinguished Names), parse and format them

DEPENDS+=	p5-Parse-RecDescent>=1.80:../../devel/p5-Parse-RecDescent

PERL5_PACKLIST=	auto/X500/DN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
