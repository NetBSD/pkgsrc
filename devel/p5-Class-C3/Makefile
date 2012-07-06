# $NetBSD: Makefile,v 1.12 2012/07/06 09:11:22 sno Exp $

DISTNAME=	Class-C3-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-C3/
COMMENT=	Pragma to use the C3 method resolution order algortihm
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Algorithm-C3-[0-9]*:../../devel/p5-Algorithm-C3

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/C3/.packlist

# As the minimum required version by pkgsrc for Perl 5 is 5.10, this
# package for the Perl 5 module Class::C3 does not need any dependency:
# it is only a stub for the CORE module mro, available since Perl
# version 5.9.5

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
