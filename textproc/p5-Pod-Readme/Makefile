# $NetBSD: Makefile,v 1.12 2015/01/11 15:29:44 wen Exp $

DISTNAME=	Pod-Readme-v1.1.2
PKGNAME=	p5-${DISTNAME:S/v1/1/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Readme/
COMMENT=	Convert POD to README file
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-CPAN-Changes>=0.30:../../devel/p5-CPAN-Changes
DEPENDS+=	p5-Moo>=1.004005:../../devel/p5-Moo
DEPENDS+=	p5-MooX-HandlesVia>=0:../../devel/p5-MooX-HandlesVia
DEPENDS+=	p5-Path-Tiny>=0.018:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Type-Tiny>=0:../../devel/p5-Type-Tiny

PERL5_PACKLIST=		auto/Pod/Readme/.packlist
#PERL5_MODULE_TYPE=	Module::Build

REPLACE_PERL+=		bin/pod2readme

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
