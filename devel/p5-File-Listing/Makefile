# $NetBSD: Makefile,v 1.3 2011/08/12 09:25:48 obache Exp $
#

DISTNAME=	File-Listing-6.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Listing/
COMMENT=	Perl 5 module providing a directory parser
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Listing/.packlist

DEPENDS+=       p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
