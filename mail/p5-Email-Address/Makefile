# $NetBSD: Makefile,v 1.33 2022/06/28 11:34:24 wiz Exp $

DISTNAME=	Email-Address-1.912
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Address
COMMENT=	RFC 2822 Address Parsing and Creation
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Email/Address/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
