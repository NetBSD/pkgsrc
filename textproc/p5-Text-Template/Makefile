# $NetBSD: Makefile,v 1.14 2004/12/20 11:31:10 grant Exp $
#

DISTNAME=       Text-Template-1.43
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tte
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.plover.com/~mjd/perl/Template/
COMMENT=	Perl5 library for generating form letters

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
