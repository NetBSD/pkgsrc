# $NetBSD: Makefile,v 1.18 2014/05/29 23:37:31 wiz Exp $
#

DISTNAME=		Sys-Hostname-Long-1.4
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
SVR4_PKGNAME=		p5shl
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sys-Hostname-Long/
COMMENT=		Try to get the full hostname in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

REPLACE_PERL+=		testall.pl

PERL5_PACKLIST=		auto/Sys/Hostname/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
