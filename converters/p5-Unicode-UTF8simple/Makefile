# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:17 joerg Exp $
#

DISTNAME=	Unicode-UTF8simple-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gus/Unicode-UTF8simple-1.06/
COMMENT=	Conversions to/from UTF8 from/to charactersets

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Unicode/UTF8simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
