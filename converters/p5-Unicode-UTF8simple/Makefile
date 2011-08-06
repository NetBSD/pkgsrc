# $NetBSD: Makefile,v 1.6 2011/08/06 14:42:14 adam Exp $

DISTNAME=	Unicode-UTF8simple-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gus/Unicode-UTF8simple/
COMMENT=	Conversions to/from UTF8 from/to charactersets

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Unicode/UTF8simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
