# $NetBSD: Makefile,v 1.2 2010/08/21 16:34:45 seb Exp $
#

DISTNAME=	boolean-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=  ${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/perldoc?boolean
COMMENT=	Boolean support for Perl

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/boolean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
