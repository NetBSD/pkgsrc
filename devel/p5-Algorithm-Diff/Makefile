# $NetBSD: Makefile,v 1.28 2019/06/30 20:14:30 nia Exp $

DISTNAME=	Algorithm-Diff-1.1903
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Diff
COMMENT=	Perl module for diffing similar to diff(1)

USE_LANGUAGES=		# empty

REPLACE_PERL+=		cdiff.pl diff.pl diffnew.pl htmldiff.pl
PERL5_PACKLIST=		auto/Algorithm/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
