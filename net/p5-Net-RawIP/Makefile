# $NetBSD: Makefile,v 1.5 2007/03/07 16:46:39 gson Exp $
#

DISTNAME=	Net-RawIP-0.21_03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nsn
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SZ/SZABGAB/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~szabgab/Net-RawIP-0.21_03/
COMMENT=	Perl extension to manipulate raw ip packets with interface to libpcap

DEPENDS+=              p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

PERL5_PACKLIST=		auto/Net/RawIP/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
