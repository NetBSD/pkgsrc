# $NetBSD: Makefile,v 1.14 2005/09/28 14:31:08 rillig Exp $
#

DISTNAME=	Text-Balanced-1.94
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tba
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=	Extract delimited text sequences from strings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
