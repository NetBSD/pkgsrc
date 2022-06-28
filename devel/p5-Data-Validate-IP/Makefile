# $NetBSD: Makefile,v 1.6 2022/06/28 11:32:13 wiz Exp $

DISTNAME=	Data-Validate-IP-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Validate-IP
COMMENT=	IPv4 and IPv6 validation methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-NetAddr-IP>=4:../../net/p5-NetAddr-IP

PERL5_PACKLIST=	auto/Data/Validate/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
