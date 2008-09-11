# $NetBSD: Makefile,v 1.3 2008/09/11 12:38:06 he Exp $
#

DISTNAME=	B-Utils-0.06
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
