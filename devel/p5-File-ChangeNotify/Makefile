# $NetBSD: Makefile,v 1.30 2018/08/22 09:44:00 wiz Exp $

DISTNAME=	File-ChangeNotify-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-ChangeNotify/
COMMENT=	Watch for changes to files, cross-platform style
LICENSE=	artistic-2.0

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-MooseX-Params-Validate>=0.08:../../devel/p5-MooseX-Params-Validate
DEPENDS+=	p5-MooseX-SemiAffordanceAccessor-[0-9]*:../../devel/p5-MooseX-SemiAffordanceAccessor
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

# for make test
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/File/ChangeNotify/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
DEPENDS+=	p5-IO-KQueue-[0-9]*:../../sysutils/p5-IO-KQueue
.elif ${OPSYS} == "Linux"
DEPENDS+=	p5-Linux-Inotify2>=1.2:../../sysutils/p5-Linux-Inotify2
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
