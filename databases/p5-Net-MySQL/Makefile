# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:03 seb Exp $
#

DISTNAME=	Net-MySQL-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/O/OY/OYAMA/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/O/OY/OYAMA/
COMMENT=	Net::MySQL - Pure Perl MySQL network protocol interface

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/MySQL/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
