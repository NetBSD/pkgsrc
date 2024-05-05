# $NetBSD: Makefile,v 1.1 2024/05/05 07:22:32 wiz Exp $

DISTNAME=	CPAN-Requirements-Dynamic-0.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/CPAN-Requirements-Dynamic
COMMENT=	Dynamic prerequisites in meta files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Config-[0-9]*:../../devel/p5-ExtUtils-Config
DEPENDS+=	p5-CPAN-Meta-Requirements-[0-9]*:../../devel/p5-CPAN-Meta-Requirements

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/CPAN/Requirements/Dynamic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
