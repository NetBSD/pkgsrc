# $NetBSD: Makefile,v 1.39 2020/08/31 18:11:16 wiz Exp $

DISTNAME=	Digest-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest
COMMENT=	Perl5 base class for Digest:: modules
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.8.1,p5-MIME-Base64>=2.18}:../../converters/p5-MIME-Base64

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
