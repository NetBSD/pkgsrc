# $NetBSD: Makefile,v 1.20 2024/11/16 12:06:42 wiz Exp $

DISTNAME=	Biblio-EndnoteStyle-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Biblio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Biblio-EndnoteStyle
COMMENT=	Reference formatting using Endnote-like templates
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Biblio/EndnoteStyle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
