# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:49 he Exp $

DISTNAME=	Class-ISA-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
