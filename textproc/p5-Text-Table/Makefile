# $NetBSD: Makefile,v 1.9 2019/08/11 13:23:47 wiz Exp $

DISTNAME=	Text-Table-1.133
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Table
COMMENT=	Perl module to generate formatted text tables
LICENSE=	mit

BUILD_DEPENDS+= p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

DEPENDS+=	p5-Text-Aligner-[0-9]*:../../textproc/p5-Text-Aligner

PERL5_PACKLIST= auto/Text/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
