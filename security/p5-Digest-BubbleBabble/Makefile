# $NetBSD: Makefile,v 1.11 2011/08/09 07:31:42 adam Exp $

DISTNAME=	Digest-BubbleBabble-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bbl
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-BubbleBabble/
COMMENT=	Perl5 module for bubble babble fingerprints
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

PERL5_PACKLIST=		auto/Digest/BubbleBabble/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
