# $NetBSD: Makefile,v 1.12 2019/06/30 20:16:05 nia Exp $
#

DISTNAME=	Acme-Padre-PlayCode-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Acme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Acme-Padre-PlayCode
COMMENT=	Acme::PlayCode Plugin for Padre
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Locale-Msgfmt>=0.14:../../devel/p5-Locale-Msgfmt

DEPENDS+=	p5-Acme-PlayCode-[0-9]*:../../devel/p5-Acme-PlayCode
DEPENDS+=	p5-Padre>=0.43:../../editors/p5-Padre

PERL5_PACKLIST=		auto/Acme/Padre/PlayCode/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
