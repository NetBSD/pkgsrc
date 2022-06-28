# $NetBSD: Makefile,v 1.29 2022/06/28 11:33:12 wiz Exp $

DISTNAME=	Scope-Upper-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Scope-Upper
COMMENT=	Perl5 module to act on upper scopes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Scope/Upper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
