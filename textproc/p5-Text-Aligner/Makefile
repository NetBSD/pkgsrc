# $NetBSD: Makefile,v 1.9 2020/09/07 14:53:25 wiz Exp $

DISTNAME=	Text-Aligner-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Aligner
COMMENT=	Perl module to align text
LICENSE=	mit

BUILD_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

PERL5_PACKLIST=	auto/Text/Aligner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
