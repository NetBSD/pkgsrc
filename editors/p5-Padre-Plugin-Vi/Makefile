# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 18:32:32 sno Exp $
#

DISTNAME=	Padre-Plugin-Vi-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Vi/
COMMENT=	Padre plugin proving a vi keyboard
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Padre>=0.25:../../editors/p5-Padre

PERL5_PACKLIST=		auto/Padre/Plugin/Vi/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
