# $NetBSD: Makefile,v 1.20 2019/06/30 20:15:16 nia Exp $
#

DISTNAME=	Log-LogLite-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Log-LogLite
COMMENT=	Simple logging class for Perl

DEPENDS+=	p5-IO-LockedFile>=0.23:../../devel/p5-IO-LockedFile

PERL5_PACKLIST=		auto/Log/LogLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
