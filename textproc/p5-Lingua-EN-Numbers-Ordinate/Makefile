# $NetBSD: Makefile,v 1.26 2023/07/06 09:41:39 wiz Exp $
#

DISTNAME=		Lingua-EN-Numbers-Ordinate-1.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Lingua-EN-Numbers-Ordinate
COMMENT=		Go from cardinal number (3) to ordinal ("3rd")

#DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Lingua/EN/Numbers/Ordinate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
