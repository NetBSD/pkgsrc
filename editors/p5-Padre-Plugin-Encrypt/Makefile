# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 21:41:26 sno Exp $
#

DISTNAME=	Padre-Plugin-Encrypt-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-Encrypt/
COMMENT=	Padre plugin to encrypt/decrypt file
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=	p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=	p5-Padre>=0.26:../../editors/p5-Padre

PERL5_PACKLIST=		auto/Padre/Plugin/Encrypt/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
