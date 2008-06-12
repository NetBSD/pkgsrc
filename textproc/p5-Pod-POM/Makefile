# $NetBSD: Makefile,v 1.17 2008/06/12 02:14:48 joerg Exp $
#

DISTNAME=	Pod-POM-0.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
# PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	P5 module to format POD into an object format, hence POM

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
