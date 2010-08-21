# $NetBSD: Makefile,v 1.6 2010/08/21 16:36:04 seb Exp $

DISTNAME=	Text-Diff-Parser-0.1001
PKGNAME=	p5-${DISTNAME:S/1001/10.01/}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Diff-Parser/
COMMENT=	Parse patch files containing unified and standard diffs
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Diff/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
