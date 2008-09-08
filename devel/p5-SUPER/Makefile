# $NetBSD: Makefile,v 1.2 2008/09/08 21:26:21 seb Exp $
#

DISTNAME=	SUPER-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SUPER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SUPER/
COMMENT=	Perl 5 module to control superclass method dispatch

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/SUPER/.packlist

DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
