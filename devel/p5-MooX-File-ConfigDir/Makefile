# $NetBSD: Makefile,v 1.15 2021/05/24 19:51:06 wiz Exp $

DISTNAME=	MooX-File-ConfigDir-0.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-File-ConfigDir
COMMENT=	Moo eXtension for File::ConfigDir
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ConfigDir>=0.011:../../devel/p5-File-ConfigDir
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=		auto/MooX/File/ConfigDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
