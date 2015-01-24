# $NetBSD: Makefile,v 1.4 2015/01/24 10:30:22 wen Exp $

DISTNAME=	MooX-File-ConfigDir-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rehsack/MooX-File-ConfigDir
COMMENT=	Moo eXtension for File::ConfigDir
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ConfigDir>=0.011:../../devel/p5-File-ConfigDir
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=		auto/MooX/File/ConfigDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
