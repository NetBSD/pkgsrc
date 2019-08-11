# $NetBSD: Makefile,v 1.5 2019/08/11 13:20:39 wiz Exp $

DISTNAME=		TheSchwartz-1.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/J/JF/JFEARN/

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/TheSchwartz
COMMENT=		Reliable job queue system
LICENSE=		artistic-2.0

DEPENDS+=		p5-Data-ObjectDriver>=0.04:../../devel/p5-Data-ObjectDriver
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
#DEPENDS+=		p5-Storable-[0-9]*:../../devel/p5-Storable

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TheSchwartz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
