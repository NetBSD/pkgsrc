# $NetBSD: Makefile,v 1.22.2.1 2011/12/04 01:52:57 sbd Exp $

DISTNAME=	Digest-1.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dig
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest/
COMMENT=	Perl5 base class for Digest:: modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-Base64>=2.18:../../converters/p5-MIME-Base64

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
