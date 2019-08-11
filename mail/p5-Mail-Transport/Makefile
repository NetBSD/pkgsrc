# $NetBSD: Makefile,v 1.2 2019/08/11 13:21:38 wiz Exp $

DISTNAME=	Mail-Transport-3.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-Transport
COMMENT=	Use Mail Transfer Agents (MTAs)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mail-Message>=3:../../mail/p5-Mail-Message

PERL5_PACKLIST=	auto/Mail/Transport/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
