# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:54 wiz Exp $

DISTNAME=	constant-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=constant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/constant/
COMMENT=	Perl pragma to declare constants
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/constant/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
