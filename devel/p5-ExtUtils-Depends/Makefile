# $NetBSD: Makefile,v 1.36 2021/05/24 19:50:37 wiz Exp $

DISTNAME=	ExtUtils-Depends-0.8000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Depends/
COMMENT=	Easily build XS extensions that depend on XS extensions
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/Depends/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
