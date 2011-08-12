# $NetBSD: Makefile,v 1.6 2011/08/12 12:27:44 adam Exp $

DISTNAME=	ex-lib-0.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ex-lib/
COMMENT=	Perl 5 module to add in @INC absolute paths from relative ones
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-lib-abs>=0.90:../../devel/p5-lib-abs

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ex/lib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
