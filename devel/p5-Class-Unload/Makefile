# $NetBSD: Makefile,v 1.1.1.1 2009/12/04 23:37:07 seb Exp $
#

DISTNAME=	Class-Unload-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Unload/
COMMENT=	Perl 5 module to unload a class

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/Class/Unload/.packlist

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
