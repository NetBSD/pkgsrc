# $NetBSD: Makefile,v 1.22 2023/07/06 09:38:52 wiz Exp $

DISTNAME=	Context-Preserve-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Context-Preserve
COMMENT=	Perl 5 module to run code after a subroutine call
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Context/Preserve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
