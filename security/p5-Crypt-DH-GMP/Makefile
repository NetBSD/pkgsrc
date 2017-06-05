# $NetBSD: Makefile,v 1.4 2017/06/05 14:24:29 ryoon Exp $

DISTNAME=	Crypt-DH-GMP-0.00012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dmaki/Crypt-DH-GMP/
COMMENT=	Crypt::DH Using GMP Directly
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
DEPENDS+=	p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput

# cannot open GMP.xs: No such file or directory
MAKE_JOBS_SAFE=		no

PERL5_PACKLIST=	auto/Crypt/DH/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
