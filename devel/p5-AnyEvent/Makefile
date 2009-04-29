# $NetBSD: Makefile,v 1.12 2009/04/29 23:06:24 sno Exp $
#

DISTNAME=	AnyEvent-4.4
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	devel
#MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/AnyEvent/.packlist

# XXX add options for recommented dependencies:
#  EV:           3.05
#  Guard:        1.02
#  JSON:         2.09
#  JSON::XS:     2.2
#  Net::SSLeay:  1.32

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
