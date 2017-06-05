# $NetBSD: Makefile,v 1.14 2017/06/05 14:24:49 ryoon Exp $

DISTNAME=	Text-Diff-Parser-0.1001
PKGNAME=	p5-${DISTNAME:S/1001/10.01/}
PKGREVISION=	8
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Diff-Parser/
COMMENT=	Parse patch files containing unified and standard diffs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Diff/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
