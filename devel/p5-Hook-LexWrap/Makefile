# $NetBSD: Makefile,v 1.8 2010/08/04 05:17:28 seb Exp $
#

DISTNAME=	Hook-LexWrap-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hlw
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hook-LexWrap/
COMMENT=	Perl5 module providing lexically scoped subroutine wrappers
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hook/LexWrap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
