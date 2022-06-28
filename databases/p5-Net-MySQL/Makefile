# $NetBSD: Makefile,v 1.22 2022/06/28 11:31:28 wiz Exp $

DISTNAME=	Net-MySQL-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
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
