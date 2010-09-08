# $NetBSD: Makefile,v 1.26 2010/09/08 06:28:25 sno Exp $
#

DISTNAME=		Devel-StackTrace-1.25
PKGNAME=		p5-${DISTNAME}00
#PKGREVISION=		1
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Devel-StackTrace/
COMMENT=		Perl5 module for stack trace and stack trace frame objects
LICENSE=		artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
