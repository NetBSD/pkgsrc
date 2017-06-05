# $NetBSD: Makefile,v 1.23 2017/06/05 14:22:34 ryoon Exp $

DISTNAME=	Any-Moose-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Any/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Any-Moose/
COMMENT=	Perl extension to check dependencies on Moose or Mouse
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Role-Tiny-[0-9]*:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
# for make test
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=	auto/Any/Moose/.packlist

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
