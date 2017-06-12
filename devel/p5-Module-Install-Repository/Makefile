# $NetBSD: Makefile,v 1.6 2017/06/12 12:38:46 maya Exp $

DISTNAME=	Module-Install-Repository-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-Repository/
COMMENT=	Perl 5 module for finding the repository root
LICENSE=	${PERL5_LICENSE}

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Module/Install/Repository/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
