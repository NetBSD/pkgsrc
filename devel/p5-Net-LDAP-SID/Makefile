# $NetBSD: Makefile,v 1.10 2021/05/24 19:51:16 wiz Exp $

DISTNAME=	Net-LDAP-SID-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KARMAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::LDAP::SID
COMMENT=	Active Directory Security Identifier manipulation
LICENSE=	artistic-2.0


PERL5_PACKLIST=	auto/Net/LDAP/SID/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
