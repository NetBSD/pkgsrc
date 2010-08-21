# $NetBSD: Makefile,v 1.2 2010/08/21 16:33:25 seb Exp $
#

DISTNAME=	Class-XSAccessor-Array-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-XSAccessor-Array/
COMMENT=	Perl 5 module to generate fast XS accessors for array based objects
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-AutoXS-Header>=1.02:../../devel/p5-AutoXS-Header

PERL5_PACKLIST=	auto/Class/XSAccessor/Array/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
