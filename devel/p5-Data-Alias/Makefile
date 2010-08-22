# $NetBSD: Makefile,v 1.4 2010/08/22 05:32:33 sno Exp $

DISTNAME=	Data-Alias-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Alias/
COMMENT=	Comprehensive set of aliasing operations

# see https://rt.cpan.org/Ticket/Display.html?id=36165
PKG_FAIL_REASON=	Broken with perl-5.12

PERL5_PACKLIST=	auto/Data/Alias/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
