# $NetBSD: Makefile,v 1.13 2008/01/08 15:11:25 heinz Exp $
#

DISTNAME=		Digest-SHA-5.45
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA/
COMMENT=		Perl module for SHA-1/224/256/384/512 algorithms

PKG_DESTDIR_SUPPORT=	user-destdir

#LICENSE=		gnu-gpl-v2 # under same terms as Perl

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Digest/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
