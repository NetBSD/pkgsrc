# $NetBSD: Makefile,v 1.4 2011/08/10 06:45:27 adam Exp $

DISTNAME=	Compress-PPMd-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-PPMd/
COMMENT=	Perl 5 module interface to the Dmitry Shkarin PPMd compression library
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
PERL5_PACKLIST=		auto/Compress/PPMd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
