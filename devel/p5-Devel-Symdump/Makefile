# $NetBSD: Makefile,v 1.49 2022/06/28 11:32:19 wiz Exp $

DISTNAME=	Devel-Symdump-2.18
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Symdump
COMMENT=	Perl5 module for inspecting perl's symtable/class hiers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Devel/Symdump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
