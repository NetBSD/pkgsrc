# $NetBSD: Makefile,v 1.10 2003/06/02 01:16:32 jschauma Exp $
#

DISTNAME=       Text-Template-1.43
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tte
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.plover.com/~mjd/perl/Template/
COMMENT=	perl5 library for generating form letters

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
