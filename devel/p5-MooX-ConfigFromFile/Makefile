# $NetBSD: Makefile,v 1.16 2021/05/24 19:51:06 wiz Exp $

DISTNAME=	MooX-ConfigFromFile-0.009
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-ConfigFromFile
COMMENT=	Moo eXtension for initializing objects from config file
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Any-[0-9]*:../../devel/p5-Config-Any
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-MooX-File-ConfigDir-[0-9]*:../../devel/p5-MooX-File-ConfigDir
BUILD_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON

PERL5_PACKLIST=		auto/MooX/ConfigFromFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
