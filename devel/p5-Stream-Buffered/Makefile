# $NetBSD: Makefile,v 1.2 2013/05/31 12:40:44 wiz Exp $

DISTNAME=	Stream-Buffered-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Stream/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Stream-Buffered/
COMMENT=	Perl extension for temporary buffer to save bytes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Stream/Buffered/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
