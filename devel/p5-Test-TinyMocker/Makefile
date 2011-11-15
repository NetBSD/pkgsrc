# $NetBSD: Makefile,v 1.1.1.1 2011/11/15 13:13:13 sno Exp $

DISTNAME=	Test-TinyMocker-0.03 
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-TinyMocker/
COMMENT=	Very simple Perl5 tool to mock external modules
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/Test/TinyMocker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
