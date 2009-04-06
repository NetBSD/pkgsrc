# $NetBSD: Makefile,v 1.1.1.1 2009/04/06 18:56:46 chuck Exp $

DISTNAME=	Statistics-Descriptive-2.6
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Statistics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Statistics-Descriptive/
COMMENT=	Perl module of basic descriptive statistical functions

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Statistics/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
