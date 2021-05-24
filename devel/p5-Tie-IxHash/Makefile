# $NetBSD: Makefile,v 1.34 2021/05/24 19:51:53 wiz Exp $
#

DISTNAME=	Tie-IxHash-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-IxHash
COMMENT=	Perl module that implements ordered in-memory associative arrays
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Tie/IxHash/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
