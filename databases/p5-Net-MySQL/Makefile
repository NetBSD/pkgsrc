# $NetBSD: Makefile,v 1.14 2018/08/22 09:43:19 wiz Exp $
#

DISTNAME=	Net-MySQL-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TS/TSUCCHI/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/O/OY/OYAMA/
COMMENT=	Net::MySQL - Pure Perl MySQL network protocol interface

DEPENDS+=       p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

PERL5_PACKLIST=	auto/Net/MySQL/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
