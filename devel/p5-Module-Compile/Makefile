# $NetBSD: Makefile,v 1.8 2022/06/28 11:32:45 wiz Exp $

DISTNAME=	Module-Compile-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Compile
COMMENT=	Perl Module Compilation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Module/Compile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
