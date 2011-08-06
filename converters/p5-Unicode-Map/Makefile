# $NetBSD: Makefile,v 1.5 2011/08/06 14:36:36 adam Exp $

DISTNAME=	Unicode-Map-0.112
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-Map/
COMMENT=	Perl5 module that maps charsets from and to utf16 unicode

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Unicode/Map/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
