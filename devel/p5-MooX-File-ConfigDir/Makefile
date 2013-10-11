# $NetBSD: Makefile,v 1.1 2013/10/11 11:30:58 wiz Exp $

DISTNAME=	MooX-File-ConfigDir-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rehsack/MooX-File-ConfigDir
COMMENT=	Moo eXtension for File::ConfigDir
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ConfigDir>=0.006:../../devel/p5-File-ConfigDir
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

PERL5_PACKLIST=		auto/MooX/File/ConfigDir/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
