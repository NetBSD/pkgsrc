# $NetBSD: Makefile,v 1.16 2026/07/16 19:05:12 wiz Exp $

DISTNAME=	Text-Aligner-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Aligner
COMMENT=	Perl module to align text
LICENSE=	mit

TOOL_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

PERL5_PACKLIST=	auto/Text/Aligner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
