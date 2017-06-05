# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:50 ryoon Exp $

DISTNAME=	Devel-Autoflush-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Autoflush/
COMMENT=	Perl module to set autoflush from the command line
LICENSE=	apache-2.0

BUILD_DEPENDS+=	p5-IO-CaptureOutput>=1.08:../../devel/p5-IO-CaptureOutput

PERL5_PACKLIST=		auto/Devel/Autoflush/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
