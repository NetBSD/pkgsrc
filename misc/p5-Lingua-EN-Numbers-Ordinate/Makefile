# $NetBSD: Makefile,v 1.2 2005/02/19 20:39:21 wiz Exp $
#

DISTNAME=		Lingua-EN-Numbers-Ordinate-1.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Lingua-EN-Numbers-Ordinate/
COMMENT=		Go from cardinal number (3) to ordinal ("3rd")

#DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Lingua/EN/Numbers/Ordinate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
