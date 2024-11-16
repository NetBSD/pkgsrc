# $NetBSD: Makefile,v 1.24 2024/11/16 12:05:53 wiz Exp $

DISTNAME=	Mail-SPF-3.20240617
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	aniou@smutek.pl
HOMEPAGE=	https://metacpan.org/release/Mail-SPF
COMMENT=	Perl implementation of the Sender Policy Framework
LICENSE=	modified-bsd

DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error
DEPENDS+=	p5-NetAddr-IP>=4.000:../../net/p5-NetAddr-IP
DEPENDS+=	p5-Net-DNS>=0.58:../../net/p5-Net-DNS
DEPENDS+=	p5-URI>=1.13:../../www/p5-URI

TEST_DEPENDS+=	p5-Net-DNS-Resolver-Programmable-[0-9]*:../../net/p5-Net-DNS-Resolver-Programmable

REPLACE_PERL=		sbin/spfd bin/spfquery

PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Mail/SPF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
