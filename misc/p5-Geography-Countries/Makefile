# $NetBSD: Makefile,v 1.1.1.1 2003/06/29 22:56:13 gson Exp $
#

DISTNAME=		Geography-Countries-1.4
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5gcn
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geography/}

MAINTAINER=		gson@netbsd.org
COMMENT=		perl5 module for mapping contry names and codes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Geography/Countries/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
