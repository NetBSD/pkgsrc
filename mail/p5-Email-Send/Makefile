# $NetBSD: Makefile,v 1.28 2019/08/11 13:21:33 wiz Exp $

DISTNAME=	Email-Send-2.201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Send
COMMENT=	Email::Send - Simply Sending Email
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=	p5-Module-Pluggable>=2.97:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Return-Value>=1.28:../../devel/p5-Return-Value

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Email/Send/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
