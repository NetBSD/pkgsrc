# $NetBSD: Makefile,v 1.2 2010/08/21 16:33:13 seb Exp $
#

DISTNAME=	AutoXS-Header-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AutoXS-Header/
COMMENT=	Perl 5 module container for the AutoXS header files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AutoXS/Header/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
