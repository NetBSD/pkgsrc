# $NetBSD: Makefile,v 1.30 2023/07/06 09:39:21 wiz Exp $
#

DISTNAME=		IO-Null-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Null
COMMENT=		Perl module for null filehandles

PERL5_PACKLIST=		auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
