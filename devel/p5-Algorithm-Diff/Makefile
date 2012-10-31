# $NetBSD: Makefile,v 1.19 2012/10/31 11:17:36 asau Exp $

DISTNAME=	Algorithm-Diff-1.1902
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Diff/
COMMENT=	Perl module for diffing similar to diff(1)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

REPLACE_PERL+=		cdiff.pl diff.pl diffnew.pl htmldiff.pl
PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
