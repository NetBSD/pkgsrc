# $NetBSD: Makefile,v 1.32 2011/08/14 12:26:15 obache Exp $

DISTNAME=	Log-Dispatch-2.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate

PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
