# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 21:44:12 sno Exp $
#

DISTNAME=	Padre-Plugin-SVN-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-SVN/
COMMENT=	Simple SVN interface for Padre
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Padre>=0.27:../../editors/p5-Padre
DEPENDS+=	p5-SVN-Class>=0.15:../../devel/p5-SVN-Class

PERL5_PACKLIST=		auto/Padre/Plugin/SVN/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
