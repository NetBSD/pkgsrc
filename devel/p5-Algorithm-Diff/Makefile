# $NetBSD: Makefile,v 1.13 2007/06/09 23:25:15 abs Exp $

DISTNAME=	Algorithm-Diff-1.1902
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Diff/
COMMENT=	Perl module for diffing similar to diff(1)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=		cdiff.pl diff.pl diffnew.pl htmldiff.pl

PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
