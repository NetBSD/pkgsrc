# $NetBSD: Makefile,v 1.14 2022/06/28 11:35:46 wiz Exp $
#

DISTNAME=		Dancer-Plugin-Auth-RBAC-1.110720
PKGNAME=		p5-${DISTNAME:S/110720/110.720/}
PKGREVISION=		9
CATEGORIES=		security www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Dancer/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Dancer-Plugin-Auth-RBAC
COMMENT=		Dancer Authentication, Security and Role-Based Access Control Framework
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Dancer-[0-9]*:../../www/p5-Dancer
DEPENDS+=		p5-YAML-[0-9]*:../../textproc/p5-YAML

# XXX
#RECOMMENDED+=		p5-Dancer-Plugin-Database-[0-9]*:../../database/p5-Dancer-Plugin-Database

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Dancer/Plugin/Auth/RBAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
