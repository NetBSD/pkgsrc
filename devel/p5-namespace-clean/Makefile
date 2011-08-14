# $NetBSD: Makefile,v 1.10 2011/08/14 12:26:49 obache Exp $

DISTNAME=	namespace-clean-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-clean/
COMMENT=	Perl module to keep imports and functions out of your namespace
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.07:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-Package-Stash>=0.03:../../devel/p5-Package-Stash
DEPENDS+=	p5-Sub-Identify>=0.04:../../devel/p5-Sub-Identify
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/namespace/clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
