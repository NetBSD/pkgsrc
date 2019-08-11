# $NetBSD: Makefile,v 1.39 2019/08/11 13:20:43 wiz Exp $

DISTNAME=	Variable-Magic-0.62
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Variable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Variable-Magic
COMMENT=	Perl 5 module to associate user-defined magic to variables
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Variable/Magic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
