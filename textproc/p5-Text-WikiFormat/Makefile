# $NetBSD: Makefile,v 1.5 2005/02/27 10:54:12 wiz Exp $
#

DISTNAME=	Text-WikiFormat-0.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-WikiFormat/
COMMENT=	Translate Wiki formatted text into other formats

DEPENDS+=	p5-URI>=1.30:../../www/p5-URI

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
