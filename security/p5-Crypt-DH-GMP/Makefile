# $NetBSD: Makefile,v 1.11 2022/07/28 18:46:23 schmonz Exp $

DISTNAME=	Crypt-DH-GMP-0.00012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-DH-GMP
COMMENT=	Crypt::DH Using GMP Directly
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Devel-CheckLib>=1.16nb1:../../devel/p5-Devel-CheckLib
DEPENDS+=	p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput

# cannot open GMP.xs: No such file or directory
MAKE_JOBS_SAFE=		no

PERL5_PACKLIST=	auto/Crypt/DH/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
