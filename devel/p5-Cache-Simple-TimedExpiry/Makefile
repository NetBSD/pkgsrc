# $NetBSD: Makefile,v 1.12 2008/06/20 01:09:13 joerg Exp $

DISTNAME=	Cache-Simple-TimedExpiry-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cache-Simple-TimedExpiry/
COMMENT=	Perl module providing a lightweight cache with timed expiration

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Cache/Simple/TimedExpiry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
