# $NetBSD: Makefile,v 1.21 2021/10/01 23:49:37 wen Exp $

DISTNAME=	Config-INI-0.027
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-INI
COMMENT=	Perl 5 module to handle simple .ini-file format
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mixin-Linewise>=0.110:../../devel/p5-Mixin-Linewise

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/INI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
