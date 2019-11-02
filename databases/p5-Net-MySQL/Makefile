# $NetBSD: Makefile,v 1.17 2019/11/02 15:38:04 rillig Exp $
#

DISTNAME=	Net-MySQL-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
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
