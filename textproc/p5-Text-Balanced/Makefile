# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:48 jlam Exp $
#

DISTNAME=	Text-Balanced-1.94
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tba
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Extract delimited text sequences from strings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
