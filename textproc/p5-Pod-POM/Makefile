# $NetBSD: Makefile,v 1.20 2009/04/24 07:06:05 sno Exp $
#

DISTNAME=	Pod-POM-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM/
COMMENT=	P5 module to format POD into an object format, hence POM

BUILD_DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
