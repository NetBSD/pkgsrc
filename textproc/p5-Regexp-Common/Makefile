# $NetBSD: Makefile,v 1.20 2013/05/31 12:42:12 wiz Exp $
#

DISTNAME=		Regexp-Common-2013031301
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Regexp-Common/
COMMENT=		Provide commonly requested regular expressions
LICENSE=		mit OR modified-bsd OR artistic OR artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Regexp/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
