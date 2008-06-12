# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=	Net-Libdnet-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/V/VM/VMAN/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/V/VM/VMAN/
COMMENT=	Perl interface to libdnet

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/Libdnet/.packlist
USE_LANGUAGES+=	c

.include "../../net/libdnet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
