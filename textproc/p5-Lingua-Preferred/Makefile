# $NetBSD: Makefile,v 1.1.1.1 2005/05/19 17:31:02 reed Exp $
#

DISTNAME=		Lingua-Preferred-0.2.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Choose a preferred language from a selection

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Lingua/Preferred/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
