# $NetBSD: Makefile,v 1.1.1.1 2004/08/05 15:17:09 cube Exp $
#

DISTNAME=	Text-WikiFormat-0.72
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Translate Wiki formatted text into other formats

DEPENDS+=	p5-Module-Build>=0.21:../../devel/p5-Module-Build
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
