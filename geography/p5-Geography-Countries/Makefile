# $NetBSD: Makefile,v 1.19 2022/06/28 11:33:58 wiz Exp $
#

DISTNAME=		Geography-Countries-2009041301
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geography/}

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Geography-Countries
COMMENT=		Perl5 module for mapping country names and codes
LICENSE=		mit

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geography/Countries/.packlist

PREV_PKGPATH=		misc/p5-Geography-Countries

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
