# $NetBSD: Makefile,v 1.13 2009/05/21 11:17:41 sno Exp $
#

DISTNAME=	AnyEvent-4.41
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	devel
#MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks
LICENSE=	gnu-gpl-v2 # OR artistic

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
