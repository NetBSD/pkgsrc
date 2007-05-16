# $NetBSD: Makefile,v 1.1.1.1 2007/05/16 20:21:36 heinz Exp $
#

DISTNAME=	SVG-2.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVG/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVG/
COMMENT=	Perl module for generation of SVG images

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/SVG/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
