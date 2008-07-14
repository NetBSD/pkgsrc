# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:19:15 abs Exp $

DISTNAME=	Class-Base-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AB/ABW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Class::Base
COMMENT=	Useful base class for deriving other modules

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Class/Base/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
