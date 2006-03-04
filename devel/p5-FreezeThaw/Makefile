# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:21 jlam Exp $
#

DISTNAME=	FreezeThaw-0.43
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5frt
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FreezeThaw/
COMMENT=	Converting Perl structures to strings and back

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/FreezeThaw/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
