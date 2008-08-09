# $NetBSD: Makefile,v 1.1.1.1 2008/08/09 02:58:56 obache Exp $

DISTNAME=	Text-Diff-Parser-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Diff-Parser/
COMMENT=	Parse patch files containing unified and standard diffs

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Diff/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
