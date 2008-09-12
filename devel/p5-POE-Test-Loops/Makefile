# $NetBSD: Makefile,v 1.1.1.1 2008/09/12 12:54:04 he Exp $

DISTNAME=	POE-Test-Loops-1.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Test-Loops/
COMMENT=	Perl module providing reusable tests for POE::Loop authors

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Test/Loops/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
