# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:26 joerg Exp $
#

DISTNAME=	Sort-Maker-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sort-Maker/
COMMENT=	Perl 5 module providing a simple way to make efficient sort subs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sort/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
