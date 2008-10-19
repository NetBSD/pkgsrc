# $NetBSD: Makefile,v 1.8 2008/10/19 19:18:32 he Exp $
#

DISTNAME=	Net-RawIP-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5nsn
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-RawIP/
COMMENT=	Perl extension to manipulate raw ip packets with interface to libpcap

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	c

DEPENDS+=              p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

PERL5_PACKLIST=		auto/Net/RawIP/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
