# $NetBSD: Makefile,v 1.2 2004/12/09 18:06:21 wiz Exp $
#

DISTNAME=	Text-Quoted-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://search.cpan.org/dist/Text-Quoted/
COMMENT=	Extract the structure of a quoted mail message

DEPENDS+=	p5-Text-Autoformat>=1.04:../../textproc/p5-Text-Autoformat

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Quoted/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
