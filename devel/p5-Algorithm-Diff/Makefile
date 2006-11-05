# $NetBSD: Makefile,v 1.12 2006/11/05 17:49:34 joerg Exp $

DISTNAME=	Algorithm-Diff-1.1901
PKGNAME=	p5-${DISTNAME:S/1901/19.01/}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Diff/
COMMENT=	Perl module for diffing similar to diff(1)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=		cdiff.pl diff.pl diffnew.pl htmldiff.pl

PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
