# $NetBSD: Makefile,v 1.4 2004/12/20 11:31:10 grant Exp $
#

DISTNAME=       Text-Reform-1.11
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5trf
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/search?module=Text::Reform
COMMENT=	Manual text wrapping and reformatting

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Reform/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
