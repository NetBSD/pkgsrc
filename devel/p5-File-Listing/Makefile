# $NetBSD: Makefile,v 1.4 2011/08/13 08:00:04 adam Exp $

DISTNAME=	File-Listing-6.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Listing/
COMMENT=	Perl 5 module providing a directory parser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	p5-libwww<6.00
DEPENDS+=	p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Listing/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
