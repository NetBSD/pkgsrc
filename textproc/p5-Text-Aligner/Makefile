# $NetBSD: Makefile,v 1.6 2019/06/30 20:16:58 nia Exp $

DISTNAME=	Text-Aligner-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
