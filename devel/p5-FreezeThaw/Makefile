# $NetBSD: Makefile,v 1.9 2004/02/18 00:23:31 heinz Exp $
#

DISTNAME=	FreezeThaw-0.43
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5frt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FreezeThaw/
COMMENT=	Converting Perl structures to strings and back

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FreezeThaw/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
