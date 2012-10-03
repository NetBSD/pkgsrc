# $NetBSD: Makefile,v 1.5 2012/10/03 11:43:41 asau Exp $
#

DISTNAME=	Padre-Plugin-Kate-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Kate/
COMMENT=	Padre plugin using the Kate syntax highlighter
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Padre>=0.65:../../editors/p5-Padre
DEPENDS+=	p5-Syntax-Highlight-Engine-Kate>=0.05:../../textproc/p5-Syntax-Highlight-Engine-Kate

PERL5_PACKLIST=		auto/Padre/Plugin/Kate/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
