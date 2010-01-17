# $NetBSD: Makefile,v 1.12 2010/01/17 00:08:35 sno Exp $
#

DISTNAME=		Regexp-Common-2010010201
PKGNAME=		p5-${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Regexp-Common/
COMMENT=		Provide commonly requested regular expressions
LICENSE=		mit OR modified-bsd OR artistic OR artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Regexp/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
