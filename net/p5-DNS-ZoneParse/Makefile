# $NetBSD: Makefile,v 1.19 2011/11/17 09:10:13 hiramatsu Exp $
#

DISTNAME=	DNS-ZoneParse-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dzp
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DNS-ZoneParse/
COMMENT=	Perl5 module for parsing DNS zone files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
