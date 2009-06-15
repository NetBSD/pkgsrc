# $NetBSD: Makefile,v 1.3 2009/06/15 21:20:22 sno Exp $
#

DISTNAME=	File-ChangeNotify-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-ChangeNotify/
COMMENT=	Watch for changes to files, cross-platform style
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-MOP-[0-9]*:../../devel/p5-Class-MOP
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Params-Validate>=0.08:../../devel/p5-MooseX-Params-Validate
DEPENDS+=	p5-MooseX-SemiAffordanceAccessor-[0-9]*:../../devel/p5-MooseX-SemiAffordanceAccessor

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/ChangeNotify/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
