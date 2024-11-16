# $NetBSD: Makefile,v 1.19 2024/11/16 12:04:39 wiz Exp $

DISTNAME=	MooX-File-ConfigDir-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-File-ConfigDir
COMMENT=	Moo eXtension for File::ConfigDir
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ConfigDir>=0.018:../../devel/p5-File-ConfigDir
DEPENDS+=	p5-Moo>=1.003000:../../devel/p5-Moo
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=		auto/MooX/File/ConfigDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
