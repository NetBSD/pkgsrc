# $NetBSD: Makefile,v 1.4 2005/03/01 22:30:52 wiz Exp $
#

DISTNAME=		Regexp-Common-2.119
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://search.cpan.org/dist/Regexp-Common/
COMMENT=		Provide commonly requested regular expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Regexp/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
