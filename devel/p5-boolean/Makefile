# $NetBSD: Makefile,v 1.5 2011/12/09 02:08:33 hiramatsu Exp $

DISTNAME=	boolean-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/boolean/
COMMENT=	Boolean support for Perl
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/boolean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
