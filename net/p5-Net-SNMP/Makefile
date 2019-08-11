# $NetBSD: Makefile,v 1.41 2019/08/11 13:22:22 wiz Exp $
#

DISTNAME=	Net-SNMP-v6.0.1
PKGNAME=	p5-${DISTNAME:S/v6/6/}
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-SNMP
COMMENT=	Perl5 module for SNMP queries
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Crypt-DES>=2.03:../../security/p5-Crypt-DES
DEPENDS+=	p5-Crypt-Rijndael>=1.02:../../security/p5-Crypt-Rijndael
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.11}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1>=1.02:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Digest-HMAC>=1.00:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Socket6>=0.23:../../net/p5-Socket6

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Net/SNMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
