# $NetBSD: Makefile,v 1.21 2013/12/09 14:17:53 obache Exp $

DISTNAME=	Text-vCard-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5tv
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-vCard/
COMMENT=	Parse, edit and create vCards (RFC 2426)
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# for MIME::QuotedPrint
DEPENDS+=	{perl>=5.8.8,p5-MIME-Base64>=3.07}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp
DEPENDS+=	p5-Text-vFile-asData>=0.07:../../textproc/p5-Text-vFile-asData

PERL5_PACKLIST=	auto/Text/vCard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
