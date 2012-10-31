# $NetBSD: Makefile,v 1.6 2012/10/31 11:18:16 asau Exp $

DISTNAME=	Git-Repository-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Git-Repository/
COMMENT=	Perl interface to Git repositories
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	p5-System-Command>=1.05:../../devel/p5-System-Command

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/Repository/.packlist
PERL5_MODY_TYPE=	Module::Build

USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
