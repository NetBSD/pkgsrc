# $NetBSD: Makefile,v 1.3 2010/08/21 16:34:21 seb Exp $
#

DISTNAME=	Regexp-Parser-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Parser/
COMMENT=	Perl 5 base class for parsing regexes

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Regexp/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
