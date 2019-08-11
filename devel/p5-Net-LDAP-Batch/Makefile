# $NetBSD: Makefile,v 1.16 2019/08/11 13:20:02 wiz Exp $
#

DISTNAME=	Net-LDAP-Batch-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	databases devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-LDAP-Batch
COMMENT=	Perl 5 module to perform a batch of LDAP actions

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
BUILD_DEPENDS+=	p5-Net-LDAP-Server-Test>=0.4:../../devel/p5-Net-LDAP-Server-Test

USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Net/LDAP/Batch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
