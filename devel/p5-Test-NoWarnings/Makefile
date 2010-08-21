# $NetBSD: Makefile,v 1.6 2010/08/21 16:34:35 seb Exp $

DISTNAME=	Test-NoWarnings-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-NoWarnings/
COMMENT=	Perl5 module to make sure you didn't emit any warnings while testing
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-Test-Tester>=0.103:../../devel/p5-Test-Tester

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/Test/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
