# $NetBSD: Makefile,v 1.19 2024/11/16 12:06:08 wiz Exp $
#

DISTNAME=	Cisco-Abbrev-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cisco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Cisco-Abbrev
COMMENT=	Perl 5 module to translate to/from Cisco interface abbbreviations
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Cisco/Abbrev/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
