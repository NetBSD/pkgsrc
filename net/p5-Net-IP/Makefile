# $NetBSD: Makefile,v 1.13 2010/08/21 16:35:24 seb Exp $
#

DISTNAME=	Net-IP-1.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~manu/Net-IP-1.20/
COMMENT=	Perl extension for manipulating IPv4/IPv6 addresses
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Math-BigInteger-[0-9]*:../../math/p5-Math-BigInteger

PERL5_PACKLIST=		auto/Net/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
