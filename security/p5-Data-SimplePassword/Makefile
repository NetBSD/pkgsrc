# $NetBSD: Makefile,v 1.4 2008/07/26 20:28:23 he Exp $
#

DISTNAME=		Data-SimplePassword-0.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-SimplePassword/
COMMENT=		Simple random password generator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Math-Random-MT-Perl-[0-9]*:../../math/p5-Math-Random-MT-Perl
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/SimplePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
