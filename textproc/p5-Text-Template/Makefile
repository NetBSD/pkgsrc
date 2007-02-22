# $NetBSD: Makefile,v 1.21 2007/02/22 19:01:26 wiz Exp $
#

DISTNAME=	Text-Template-1.44
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tte
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.plover.com/Template/
COMMENT=	Perl5 library for generating form letters

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
