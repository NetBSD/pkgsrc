# $NetBSD: Makefile,v 1.26 2015/02/18 03:22:27 mef Exp $
#

DISTNAME=	Tie-IxHash-1.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-IxHash/
COMMENT=	Perl module that implements ordered in-memory associative arrays
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Tie/IxHash/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
