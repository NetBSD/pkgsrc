# $NetBSD: Makefile,v 1.42 2017/06/05 14:22:53 ryoon Exp $

DISTNAME=	Devel-StackTrace-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-StackTrace/
COMMENT=	Perl5 module for stack trace and stack trace frame objects
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
