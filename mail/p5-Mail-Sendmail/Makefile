# $NetBSD: Makefile,v 1.7 2003/07/17 21:46:44 grant Exp $

DISTNAME=	Mail-Sendmail-0.78
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mse
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://alma.ch/perl/
COMMENT=	perl5 module dedicated to Sendmail

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/Sendmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
