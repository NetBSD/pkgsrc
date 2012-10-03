# $NetBSD: Makefile,v 1.4 2012/10/03 11:43:39 asau Exp $
#

DISTNAME=	Padre-Plugin-Autoformat-1.1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Autoformat/
COMMENT=	Reformat text within Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Util-[0-9]*:../../devel/p5-Module-Util
DEPENDS+=	p5-Padre>=0.30:../../editors/p5-Padre
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat

PERL5_PACKLIST=		auto/Padre/Plugin/Autoformat/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
