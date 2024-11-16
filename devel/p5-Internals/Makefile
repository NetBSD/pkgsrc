# $NetBSD: Makefile,v 1.19 2024/11/16 12:04:28 wiz Exp $
#

DISTNAME=		Internals-1.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		devel perl5
#MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Internals/} # XXX doesn't work
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STBEY/}


MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Internals
COMMENT=		Write-protect Perl variables, manipulate refcounts

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Internals/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
