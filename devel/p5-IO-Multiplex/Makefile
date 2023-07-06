# $NetBSD: Makefile,v 1.30 2023/07/06 09:39:20 wiz Exp $
#

DISTNAME=		IO-Multiplex-1.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Multiplex
COMMENT=		Perl module to manage IO on many file handles
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
