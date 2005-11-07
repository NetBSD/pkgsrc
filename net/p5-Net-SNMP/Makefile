# $NetBSD: Makefile,v 1.20 2005/11/07 13:31:06 martti Exp $
#

DISTNAME=	Net-SNMP-5.2.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nsn
#PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/DTOWN/Net-SNMP-4.1.2/
COMMENT=	Perl5 module for SNMP queries

DEPENDS+=	p5-Crypt-DES>=2.03:../../security/p5-Crypt-DES
DEPENDS+=	p5-Digest-MD5>=2.11:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1>=1.02:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Digest-HMAC>=1.00:../../security/p5-Digest-HMAC

PERL5_PACKLIST=		auto/Net/SNMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
