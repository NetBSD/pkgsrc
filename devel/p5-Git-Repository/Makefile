# $NetBSD: Makefile,v 1.3 2012/09/13 15:01:17 sno Exp $

DISTNAME=	Git-Repository-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Git-Repository/
COMMENT=	Perl interface to Git repositories
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	p5-System-Command>=1.05:../../devel/p5-System-Command

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/Repository/.packlist
PERL5_MODY_TYPE=	Module::Build

USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
