# $NetBSD: Makefile,v 1.21 2016/10/12 12:44:42 mef Exp $

DISTNAME=		Log-Dispatch-FileRotate-1.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module to log to files which archive/rotate themselves

DEPENDS+=	p5-Date-Manip>=5.0:../../devel/p5-Date-Manip
DEPENDS+=	p5-Log-Dispatch>=2.08:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate
DEPENDS+=	p5-Log-Log4perl>=1:../../devel/p5-Log-Log4perl
# for make test
BUILD_DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny

PERL5_PACKLIST=		auto/Log/Dispatch/FileRotate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
