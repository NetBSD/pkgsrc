# $NetBSD: Makefile,v 1.10 2007/12/11 12:02:30 rhaen Exp $
#

DISTNAME=	Text-WikiFormat-0.79
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-WikiFormat/
COMMENT=	Translate Wiki formatted text into other formats

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-Scalar-List-Utils>=1.14:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/WikiFormat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
