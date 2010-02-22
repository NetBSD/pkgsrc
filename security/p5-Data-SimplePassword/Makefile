# $NetBSD: Makefile,v 1.6 2010/02/22 13:32:25 sno Exp $
#

DISTNAME=		Data-SimplePassword-0.05
PKGNAME=		p5-${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-SimplePassword/
COMMENT=		Simple random password generator
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Math-Random-MT-Perl-[0-9]*:../../math/p5-Math-Random-MT-Perl
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/SimplePassword/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
