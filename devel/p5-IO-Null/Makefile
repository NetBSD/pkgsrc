# $NetBSD: Makefile,v 1.29 2022/06/28 11:32:35 wiz Exp $
#

DISTNAME=		IO-Null-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Null
COMMENT=		Perl module for null filehandles

PERL5_PACKLIST=		auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
