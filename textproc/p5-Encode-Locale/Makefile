# $NetBSD: Makefile,v 1.7 2013/05/31 12:42:09 wiz Exp $

DISTNAME=	Encode-Locale-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-Locale/
COMMENT=	Determine the locale encoding for Encode
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Encode/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
