# $NetBSD: Makefile,v 1.10 2015/06/12 10:50:02 wiz Exp $

DISTNAME=	Padre-Plugin-Git-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Git/
COMMENT=	Simple Git interface for Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.03:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Padre>=0.67:../../editors/p5-Padre
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

PERL5_PACKLIST=		auto/Padre/Plugin/Git/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
