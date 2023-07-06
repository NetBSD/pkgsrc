# $NetBSD: Makefile,v 1.19 2023/07/06 09:39:50 wiz Exp $
#

DISTNAME=	Parse-ExuberantCTags-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-ExuberantCTags
COMMENT=	Efficiently parse exuberant ctags files
LICENSE=	(${PERL5_LICENSE}) AND public-domain

PERL5_PACKLIST=		auto/Parse/ExuberantCTags/.packlist
USE_LANGUAGES=		c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
