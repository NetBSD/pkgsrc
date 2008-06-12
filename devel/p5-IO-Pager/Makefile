# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:22 joerg Exp $
#

DISTNAME=	IO-Pager-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPIERCE/}
EXTRACT_SUFX=  .tgz

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Pager-0.06/
COMMENT=	Perl module for paged I/O to the terminal

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Pager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
