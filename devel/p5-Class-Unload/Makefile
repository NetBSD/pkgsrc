# $NetBSD: Makefile,v 1.4 2011/08/10 06:35:42 adam Exp $

DISTNAME=	Class-Unload-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Unload/
COMMENT=	Perl 5 module to unload a class
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector

PERL5_PACKLIST=		auto/Class/Unload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
