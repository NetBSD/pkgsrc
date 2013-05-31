# $NetBSD: Makefile,v 1.14 2013/05/31 12:40:24 wiz Exp $
#

DISTNAME=	Hook-LexWrap-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5hlw
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hook-LexWrap/
COMMENT=	Perl5 module providing lexically scoped subroutine wrappers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hook/LexWrap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
