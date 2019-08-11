# $NetBSD: Makefile,v 1.35 2019/08/11 13:19:39 wiz Exp $

DISTNAME=		IO-Zlib-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Zlib
COMMENT=		Perl5 IO:: style interface to Compress::Zlib
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib>=2

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/IO/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
