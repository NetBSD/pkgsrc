# $NetBSD: Makefile,v 1.19 2009/03/15 08:54:43 seb Exp $
#

DISTNAME=	Pod-POM-0.18
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
# PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM/
COMMENT=	P5 module to format POD into an object format, hence POM

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
