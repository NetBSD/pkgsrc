# $NetBSD: Makefile,v 1.10 2017/06/05 14:23:56 ryoon Exp $
#

DISTNAME=	Padre-Plugin-Nopaste-0.2.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Nopaste/
COMMENT=	Send code on a nopaste website from padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-App-Nopaste-[0-9]*:../../www/p5-App-Nopaste
DEPENDS+=	p5-Module-Util-[0-9]*:../../devel/p5-Module-Util
DEPENDS+=	p5-Padre>=0.30:../../editors/p5-Padre

PERL5_PACKLIST=		auto/Padre/Plugin/Nopaste/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
