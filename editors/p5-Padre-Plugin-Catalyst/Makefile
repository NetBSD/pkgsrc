# $NetBSD: Makefile,v 1.2 2010/02/12 20:33:02 sno Exp $
#

DISTNAME=	Padre-Plugin-Catalyst-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Catalyst/
COMMENT=	Catalyst helper interface for Padre
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Catalyst-Devel>=1:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-Catalyst-Runtime>=5.70000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Padre>=0.51:../../editors/p5-Padre
DEPENDS+=	p5-Task-CatInABox>=0.03:../../www/p5-Task-CatInABox
DEPENDS+=	p5-Task-Catalyst-Tutorial>=0.06:../../www/p5-Task-Catalyst-Tutorial

BUILD_DEPENDS+=	p5-Locale-Msgfmt>=0.14:../../devel/p5-Locale-Msgfmt
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Module-Pluggable>=3.9}:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/Padre/Plugin/Catalyst/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
