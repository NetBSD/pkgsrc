# $NetBSD: Makefile,v 1.2 2003/06/02 01:20:29 jschauma Exp $
#

DISTNAME=		IO-Null-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5inu
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Perl module for null filehandles

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
