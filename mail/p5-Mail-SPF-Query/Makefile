# $NetBSD: Makefile,v 1.1.1.1 2004/02/17 22:48:18 heinz Exp $

DISTNAME=		Mail-SPF-Query-1.991
PKGNAME=                p5-${DISTNAME}
SVR4_PKGNAME=		p5msq
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://spf.pobox.com/
COMMENT=		Perl module for Sender-Permitted-From queries

DEPENDS+=		p5-Net-DNS>=0.33:../../net/p5-Net-DNS
DEPENDS+=		p5-Net-CIDR-Lite>=0.15:../../net/p5-Net-CIDR-Lite
# needs URI::Escape >= 3.20
DEPENDS+=		p5-URI>=1.18:../../www/p5-URI

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SPF/Query/.packlist
USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
