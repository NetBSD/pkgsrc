# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:22 jlam Exp $
#

DISTNAME=	IO-String-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-String/
COMMENT=	Perl module for I/O on in-core objects like strings and arrays

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
