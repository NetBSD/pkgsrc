# $NetBSD: Makefile,v 1.21 2021/05/24 19:49:40 wiz Exp $

DISTNAME=	Net-MySQL-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TS/TSUCCHI/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/Net::MySQL
COMMENT=	Net::MySQL - Pure Perl MySQL network protocol interface

DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

PERL5_PACKLIST=	auto/Net/MySQL/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
