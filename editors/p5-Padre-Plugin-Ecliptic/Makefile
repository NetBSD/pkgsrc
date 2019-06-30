# $NetBSD: Makefile,v 1.15 2019/06/30 20:16:06 nia Exp $
#

DISTNAME=	Padre-Plugin-Ecliptic-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-Ecliptic
COMMENT=	Padre plugin that provides Eclipse-like useful features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-XSAccessor>=1.05:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-File-Which>=0.05:../../devel/p5-File-Which
DEPENDS+=	p5-Padre>=0.43:../../editors/p5-Padre

BUILD_DEPENDS+=		p5-Locale-Msgfmt>=0.14:../../devel/p5-Locale-Msgfmt
BUILD_DEPENDS+=		p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.86}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=		p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=		auto/Padre/Plugin/Ecliptic/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
