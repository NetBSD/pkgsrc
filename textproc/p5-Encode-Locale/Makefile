# $NetBSD: Makefile,v 1.9 2015/01/14 13:24:16 wiz Exp $

DISTNAME=	Encode-Locale-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-Locale/
COMMENT=	Determine the locale encoding for Encode
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Encode/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
