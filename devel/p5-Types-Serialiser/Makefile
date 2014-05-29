# $NetBSD: Makefile,v 1.2 2014/05/29 23:36:26 wiz Exp $

DISTNAME=	Types-Serialiser-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Types-Serialiser/
COMMENT=	Simple data types for common serialisation formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews

LICENSE=		${PERL5_LICENSE}
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Types/Serialiser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
