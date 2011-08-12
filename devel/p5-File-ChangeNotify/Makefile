# $NetBSD: Makefile,v 1.10 2011/08/12 19:09:06 adam Exp $

DISTNAME=	File-ChangeNotify-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-ChangeNotify/
COMMENT=	Watch for changes to files, cross-platform style
LICENSE=	artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Module-Build>=0.3601:../../devel/p5-Module-Build
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Class-MOP-[0-9]*:../../devel/p5-Class-MOP
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Params-Validate>=0.08:../../devel/p5-MooseX-Params-Validate
DEPENDS+=	p5-MooseX-SemiAffordanceAccessor-[0-9]*:../../devel/p5-MooseX-SemiAffordanceAccessor
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/ChangeNotify/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
DEPENDS+=	p5-IO-KQueue-[0-9]*:../../sysutils/p5-IO-KQueue
.elif ${OPSYS} == "Linux"
DEPENDS+=	p5-Linux-Inotify2>=1.2:../../sysutils/p5-Linux-Inotify2
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
