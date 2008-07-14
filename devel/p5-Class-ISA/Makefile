# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:23:12 abs Exp $

DISTNAME=	Class-ISA-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Class::ISA
COMMENT=	Report the search path for a class's ISA tree

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Class/ISA/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
