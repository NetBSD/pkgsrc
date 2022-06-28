# $NetBSD: Makefile,v 1.15 2022/06/28 11:34:24 wiz Exp $

DISTNAME=	Email-Address-List-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Address-List
COMMENT=	RFC close address list parsing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Address>=0:../../mail/p5-Email-Address
#DEPENDS+=	{perl>=5.8.9,p5-ExtUtils-MakeMaker>=6.36}:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON

PERL5_PACKLIST=	auto/Email/Address/List/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
