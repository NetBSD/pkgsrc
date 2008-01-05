# $NetBSD: Makefile,v 1.23 2008/01/05 22:57:22 heinz Exp $
#

DISTNAME=	Date-Manip-5.48
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateManip/
COMMENT=	Perl5 module for date calculations

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
