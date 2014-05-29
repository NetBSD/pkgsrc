# $NetBSD: Makefile,v 1.8 2014/05/29 23:36:27 wiz Exp $

DISTNAME=	constant-1.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
