# $NetBSD: Makefile,v 1.3 2003/07/21 17:01:24 martti Exp $
#

DISTNAME=		Geography-Countries-1.4
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5gcn
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geography/}

MAINTAINER=		gson@NetBSD.org
COMMENT=		Perl5 module for mapping contry names and codes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Geography/Countries/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
