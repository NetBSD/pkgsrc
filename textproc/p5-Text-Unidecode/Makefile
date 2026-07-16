# $NetBSD: Makefile,v 1.28 2026/07/16 19:05:19 wiz Exp $

DISTNAME=	Text-Unidecode-1.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Unidecode
COMMENT=	Perl5 module that transliterates Unicode to US-ASCII
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Unidecode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
