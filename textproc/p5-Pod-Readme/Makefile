# $NetBSD: Makefile,v 1.10 2014/05/29 23:37:39 wiz Exp $

DISTNAME=	Pod-Readme-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Readme/
COMMENT=	Convert POD to README file
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common

PERL5_PACKLIST=		auto/Pod/Readme/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
