# $NetBSD: Makefile,v 1.43 2019/08/11 13:20:49 wiz Exp $

DISTNAME=	version-0.9924
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=version/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://metacpan.org/release/version
COMMENT=	Perl extension for Version Objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/version/.packlist
PERL5_MODULE_TYPE=	MakeMaker

REPLACE_PERL+=	lib/version.pm
REPLACE_PERL+=	vutil/lib/version/vxs.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
