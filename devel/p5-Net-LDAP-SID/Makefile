# $NetBSD: Makefile,v 1.6 2019/11/03 10:16:01 rillig Exp $

DISTNAME=	Net-LDAP-SID-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/K/KA/KARMAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/K/KA/KARMAN/
COMMENT=	Active Directory Security Identifier manipulation
LICENSE=	artistic-2.0


PERL5_PACKLIST=	auto/Net/LDAP/SID/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
