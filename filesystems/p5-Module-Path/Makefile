# $NetBSD: Makefile,v 1.3 2014/05/29 23:36:34 wiz Exp $
#

DISTNAME=	Module-Path-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Path/
COMMENT=	Perl5 module to get the full path to a locally installed module
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=	bin/mpath

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Module/Path/.packlist

BUILD_DEPENDS+=	p5-Devel-FindPerl-[0-9]*:../../devel/p5-Devel-FindPerl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
