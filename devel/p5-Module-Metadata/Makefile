# $NetBSD: Makefile,v 1.2 2014/05/29 23:36:04 wiz Exp $

DISTNAME=	Module-Metadata-1.000019
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Metadata/
COMMENT=	Gather package and POD information from perl module files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Metadata/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
