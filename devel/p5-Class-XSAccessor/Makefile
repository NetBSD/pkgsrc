# $NetBSD: Makefile,v 1.2 2009/08/27 16:01:40 joerg Exp $
#

DISTNAME=	Class-XSAccessor-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-XSAccessor/
COMMENT=	Perl 5 module to generate fast XS accessors
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-AutoXS-Header-[0-9]*:../../devel/p5-AutoXS-Header

PERL5_PACKLIST=	auto/Class/XSAccessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
