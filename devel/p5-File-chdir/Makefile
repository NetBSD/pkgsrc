# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:15 joerg Exp $
#

DISTNAME=	File-chdir-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=        ${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHWERN/}

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-chdir/
COMMENT=	Perl module with a more sensible way to change directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/chdir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
