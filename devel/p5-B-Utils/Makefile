# $NetBSD: Makefile,v 1.5 2008/12/20 19:01:33 he Exp $
#

DISTNAME=	B-Utils-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Utils/
COMMENT=	Perl 5 module providing op tree manipulation helper functions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/B/Utils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
