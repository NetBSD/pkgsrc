# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 21:34:51 sno Exp $
#

DISTNAME=	Padre-Plugin-Catalyst-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Catalyst/
COMMENT=	Catalyst helper interface for Padre
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Catalyst-Devel>=1:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-Padre>=0.43:../../editors/p5-Padre

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Module-Pluggable>=3.9}:../../devel/p5-Module-Pluggable
#BUILD_DEPENDS+= p5-Module-Build>=3.5000:../../devel/p5-Module-Build

PERL5_PACKLIST=		auto/Padre/Plugin/Catalyst/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
