# $NetBSD: Makefile,v 1.1.1.1 2005/02/19 20:03:43 wiz Exp $
#

DISTNAME=		Lingua-Preferred-0.2.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Choose a preferred language from a selection

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Lingua/Preferred/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
