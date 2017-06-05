# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:23 ryoon Exp $

DISTNAME=	Unicode-UTF8simple-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gus/Unicode-UTF8simple/
COMMENT=	Conversions to/from UTF8 from/to charactersets

PERL5_PACKLIST=	auto/Unicode/UTF8simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
