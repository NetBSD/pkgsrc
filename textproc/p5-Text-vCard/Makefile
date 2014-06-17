# $NetBSD: Makefile,v 1.24 2014/06/17 11:49:11 kleink Exp $

DISTNAME=	Text-vCard-3.06
PKGNAME=	p5-${DISTNAME}
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
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Text-Tabs+Wrap-[0-9]*:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-Text-vFile-asData>=0.07:../../textproc/p5-Text-vFile-asData
DEPENDS+=	p5-Unicode-LineBreak-[0-9]*:../../textproc/p5-Unicode-LineBreak
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=	auto/Text/vCard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
