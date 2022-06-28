# $NetBSD: Makefile,v 1.28 2022/06/28 11:33:36 wiz Exp $

DISTNAME=	UNIVERSAL-isa-1.20171012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/UNIVERSAL-isa
COMMENT=	Hack around people calling UNIVERSAL::isa() as a function
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.004,p5-CGI-[0-9]*}:../../www/p5-CGI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/UNIVERSAL/isa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
