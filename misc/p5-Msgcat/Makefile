# $NetBSD: Makefile,v 1.5 2003/07/21 17:01:25 martti Exp $
#

DISTNAME=		Msgcat-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lco
WRKSRC=			${WRKDIR}/Msgcat
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=
COMMENT=		Perl5 module to use the message catalog functions

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Msgcat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
