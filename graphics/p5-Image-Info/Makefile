# $NetBSD: Makefile,v 1.28 2011/08/14 12:59:50 obache Exp $
#

DISTNAME=	Image-Info-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5iin
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-Info/
COMMENT=	Perl module to extract meta information from images
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# missing recommends: Image::Xpm, Image::Xbm
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
#DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE=	Module::Install

PERL5_PACKLIST=		auto/Image/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
