# $NetBSD: Makefile,v 1.27 2023/07/06 09:38:54 wiz Exp $

DISTNAME=	Data-Hierarchy-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Hierarchy
COMMENT=	Perl module for handling data in a hierarchical structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Hierarchy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
