# $NetBSD: Makefile,v 1.23 2023/07/06 09:41:08 wiz Exp $
#

DISTNAME=	Net-LDAP-Server-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-LDAP-Server
COMMENT=	LDAP server side protocol handling
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap

PERL5_PACKLIST=	auto/Net/LDAP/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
