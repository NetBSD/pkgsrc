# $NetBSD: Makefile,v 1.22 2013/05/31 12:41:19 wiz Exp $

DISTNAME=	Mail-Sendmail-0.79
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5mse
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alma.ch/perl/
COMMENT=	Perl5 module dedicated to Sendmail

DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Mail/Sendmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
