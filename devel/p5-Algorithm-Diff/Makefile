# $NetBSD: Makefile,v 1.25 2016/06/08 19:22:32 wiz Exp $

DISTNAME=	Algorithm-Diff-1.1903
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Diff/
COMMENT=	Perl module for diffing similar to diff(1)

USE_LANGUAGES=		# empty

REPLACE_PERL+=		cdiff.pl diff.pl diffnew.pl htmldiff.pl
PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
