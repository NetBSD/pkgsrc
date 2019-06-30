# $NetBSD: Makefile,v 1.27 2019/06/30 20:17:05 nia Exp $

DISTNAME=	Text-WikiFormat-0.81
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-WikiFormat
COMMENT=	Translate Wiki formatted text into other formats
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.14}:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/WikiFormat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
