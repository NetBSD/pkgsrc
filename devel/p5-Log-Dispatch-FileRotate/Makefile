# $NetBSD: Makefile,v 1.35 2022/06/28 11:32:41 wiz Exp $

DISTNAME=	Log-Dispatch-FileRotate-1.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to log to files which archive/rotate themselves
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Date-Manip>=5.0:../../devel/p5-Date-Manip
DEPENDS+=	p5-Log-Dispatch>=2.59:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate
DEPENDS+=	p5-Log-Log4perl>=1:../../devel/p5-Log-Log4perl
# for make test
BUILD_DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
BUILD_DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio

PERL5_PACKLIST=		auto/Log/Dispatch/FileRotate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
