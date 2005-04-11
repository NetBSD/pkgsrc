# $NetBSD: Makefile,v 1.11 2005/04/11 21:46:21 tv Exp $

DISTNAME=	Mail-Sendmail-0.78
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mse
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://alma.ch/perl/
COMMENT=	Perl5 module dedicated to Sendmail

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/Sendmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
