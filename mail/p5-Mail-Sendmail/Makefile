# $NetBSD: Makefile,v 1.42 2026/08/19 02:28:14 wen Exp $

DISTNAME=	Mail-Sendmail-0.83
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alma.ch/perl/
COMMENT=	Perl5 module dedicated to Sendmail
LICENSE=	${PERL5_LICENSE}

DEPENDS=	p5-Sys-Hostname-Long>=0:../../sysutils/p5-Sys-Hostname-Long

PERL5_PACKLIST=		auto/Mail/Sendmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
