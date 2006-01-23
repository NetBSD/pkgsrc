# $NetBSD: Makefile,v 1.9 2006/01/23 00:35:20 rillig Exp $

DISTNAME=	Algorithm-Diff-1.1901
PKGNAME=	p5-${DISTNAME:S/1901/19.01/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Diff/
COMMENT=	Perl module for diffing similar to diff(1)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_PERL+=		cdiff.pl diff.pl diffnew.pl htmldiff.pl

PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
