# $NetBSD: Makefile,v 1.12 2019/08/11 13:19:52 wiz Exp $

DISTNAME=	Module-Metadata-1.000033
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
