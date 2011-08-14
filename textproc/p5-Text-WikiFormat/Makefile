# $NetBSD: Makefile,v 1.14 2011/08/14 15:14:15 obache Exp $
#

DISTNAME=	Text-WikiFormat-0.79
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-WikiFormat/
COMMENT=	Translate Wiki formatted text into other formats

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.14}:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/WikiFormat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
