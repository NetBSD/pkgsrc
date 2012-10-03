# $NetBSD: Makefile,v 1.7 2012/10/03 21:55:46 wiz Exp $

DISTNAME=	Test-SubCalls-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5tsc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-SubCalls/
COMMENT=	Perl5 module to track the number of times subs are called

DEPENDS+=	p5-Hook-LexWrap>=0.20:../../devel/p5-Hook-LexWrap

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Test/SubCalls/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
