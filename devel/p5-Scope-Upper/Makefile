# $NetBSD: Makefile,v 1.31 2023/07/06 09:39:59 wiz Exp $

DISTNAME=	Scope-Upper-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Scope-Upper
COMMENT=	Perl5 module to act on upper scopes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Scope/Upper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
