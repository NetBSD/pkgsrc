# $NetBSD: Makefile,v 1.2 2011/07/14 21:47:34 spz Exp $
#

DISTNAME=	File-Listing-6.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Listing/
COMMENT=	Perl 5 module providing a directory parser
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww-[0-5]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Listing/.packlist

DEPENDS+=       p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
