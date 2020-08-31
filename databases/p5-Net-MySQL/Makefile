# $NetBSD: Makefile,v 1.18 2020/08/31 18:07:05 wiz Exp $
#

DISTNAME=	Net-MySQL-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TS/TSUCCHI/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://cpan.metacpan.org/authors/id/O/OY/OYAMA/
COMMENT=	Net::MySQL - Pure Perl MySQL network protocol interface

DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

PERL5_PACKLIST=	auto/Net/MySQL/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
