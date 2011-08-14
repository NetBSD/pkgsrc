# $NetBSD: Makefile,v 1.3 2011/08/14 12:38:58 obache Exp $
#

DISTNAME=	Padre-Plugin-SpellCheck-1.1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-SpellCheck/
COMMENT=	Check spelling in Padre
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Module-Util-[0-9]*:../../devel/p5-Module-Util
DEPENDS+=	p5-Padre>=0.26:../../editors/p5-Padre
DEPENDS+=	p5-Text-Aspell-[0-9]*:../../textproc/p5-Text-Aspell

PERL5_PACKLIST=		auto/Padre/Plugin/SpellCheck/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
