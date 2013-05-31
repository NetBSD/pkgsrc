# $NetBSD: Makefile,v 1.27 2013/05/31 12:42:08 wiz Exp $
#

DISTNAME=	Convert-BER-1.32
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	4
SVR4_PKGNAME=	p5ber
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-BER/
COMMENT=	Perl class to encode/decode objects using Basic Encoding Rules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Convert/BER/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
