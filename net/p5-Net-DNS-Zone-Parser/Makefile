# $NetBSD: Makefile,v 1.10 2018/08/22 09:45:59 wiz Exp $
#

DISTNAME=	Net-DNS-Zone-Parser-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-DNS-Zone-Parser/
COMMENT=	Perl5 module for normalizing zone files

PERL5_PACKLIST=	auto/Net/DNS/Zone/Parser/.packlist

DEPENDS+=	p5-Net-DNS>=0.64:../../net/p5-Net-DNS
DEPENDS+=	p5-Net-DNS-SEC>=0.15:../../security/p5-Net-DNS-SEC

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
