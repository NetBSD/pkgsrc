# $NetBSD: Makefile,v 1.5 2011/11/25 08:15:48 hiramatsu Exp $
#

DISTNAME=	Regexp-Parser-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Parser/
COMMENT=	Perl 5 base class for parsing regexes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Regexp/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
