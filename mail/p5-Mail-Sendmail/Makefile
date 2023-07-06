# $NetBSD: Makefile,v 1.37 2023/07/06 09:40:48 wiz Exp $

DISTNAME=	Mail-Sendmail-0.80
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alma.ch/perl/
COMMENT=	Perl5 module dedicated to Sendmail
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Mail/Sendmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
