# $NetBSD: Makefile,v 1.11 2008/05/28 21:32:41 abs Exp $
#

DISTNAME=	PAR-Dist-0.29
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5moi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PAR-Dist/
COMMENT=	Perl module toolkit to create and manipulate PAR distributions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PAR/Dist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
