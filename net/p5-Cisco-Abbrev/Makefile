# $NetBSD: Makefile,v 1.14 2019/08/11 13:22:13 wiz Exp $
#

DISTNAME=	Cisco-Abbrev-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
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
