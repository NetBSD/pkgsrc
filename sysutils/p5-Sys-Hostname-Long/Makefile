# $NetBSD: Makefile,v 1.20 2014/10/09 14:06:59 wiz Exp $
#

DISTNAME=		Sys-Hostname-Long-1.4
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sys-Hostname-Long/
COMMENT=		Try to get the full hostname in Perl

USE_LANGUAGES=		# empty

REPLACE_PERL+=		testall.pl

PERL5_PACKLIST=		auto/Sys/Hostname/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
