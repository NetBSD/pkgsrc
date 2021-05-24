# $NetBSD: Makefile,v 1.11 2021/05/24 19:51:04 wiz Exp $

DISTNAME=	Module-Install-Repository-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Install-Repository
COMMENT=	Perl 5 module for finding the repository root
LICENSE=	${PERL5_LICENSE}

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Module/Install/Repository/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
