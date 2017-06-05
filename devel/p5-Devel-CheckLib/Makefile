# $NetBSD: Makefile,v 1.18 2017/06/05 14:22:51 ryoon Exp $

DISTNAME=	Devel-CheckLib-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-CheckLib/
COMMENT=	Perl extension to check that a library is available
LICENSE=	${PERL5_LICENSE}

PREV_PKGPATH=	devel/p5-Devel-Checklib

DEPENDS+=	p5-IO-CaptureOutput>=1.08.01:../../devel/p5-IO-CaptureOutput

PERL5_PACKLIST=		auto/Devel/CheckLib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
