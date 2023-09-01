# $NetBSD: Makefile,v 1.20 2023/09/01 00:50:44 wen Exp $

DISTNAME=	Perl4-CoreLibs-0.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Z/ZE/ZEFRAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Perl4-CoreLibs
COMMENT=	Libraries historically supplied with Perl 4
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Perl4/CoreLibs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
