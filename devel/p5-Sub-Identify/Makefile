# $NetBSD: Makefile,v 1.25 2023/07/06 09:40:03 wiz Exp $

DISTNAME=	Sub-Identify-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Identify
COMMENT=	Perl 5 module to retrieve names of code references
LICENSE=	${PERL5_LICENSE}

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Sub/Identify/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
