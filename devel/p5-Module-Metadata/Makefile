# $NetBSD: Makefile,v 1.13 2019/10/26 07:23:33 mef Exp $

DISTNAME=	Module-Metadata-1.000037
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Metadata
COMMENT=	Gather package and POD information from perl module files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Metadata/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
