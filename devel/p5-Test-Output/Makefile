# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:43 obache Exp $

DISTNAME=	Test-Output-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5to
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Output/
COMMENT=	Utilities to test STDOUT and STDERR messages
LICENSE=	artistic-2.0

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Tester>=0.107:../../devel/p5-Test-Tester

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Test/Output/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
