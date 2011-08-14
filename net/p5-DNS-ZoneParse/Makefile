# $NetBSD: Makefile,v 1.18 2011/08/14 14:14:41 obache Exp $
#

DISTNAME=	DNS-ZoneParse-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5dzp
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DNS-ZoneParse/
COMMENT=	Perl5 module for parsing DNS zone files

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
