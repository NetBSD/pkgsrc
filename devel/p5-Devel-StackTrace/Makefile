# $NetBSD: Makefile,v 1.28 2011/08/12 11:47:39 adam Exp $

DISTNAME=	Devel-StackTrace-1.27
PKGNAME=	p5-${DISTNAME}00
SVR4_PKGNAME=	p5dst
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace/
COMMENT=	Perl5 module for stack trace and stack trace frame objects
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
