# $NetBSD: Makefile,v 1.26 2019/08/11 13:20:48 wiz Exp $
#

DISTNAME=	prefork-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/prefork
COMMENT=	Optimize module loading across forking and non-forking scenarios
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/prefork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
