# $NetBSD: Makefile,v 1.31 2023/07/06 09:41:33 wiz Exp $
#

DISTNAME=		Sys-Hostname-Long-1.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Sys-Hostname-Long
COMMENT=		Try to get the full hostname in Perl

USE_LANGUAGES=		# empty

REPLACE_PERL+=		testall.pl

PERL5_PACKLIST=		auto/Sys/Hostname/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
