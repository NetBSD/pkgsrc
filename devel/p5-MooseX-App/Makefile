# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:19 ryoon Exp $
#

DISTNAME=	MooseX-App-1.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~maros/MooseX-App/lib/MooseX/App.pm
COMMENT=	Write user-friendly command line apps with even less suffering
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
# for make test
BUILD_DEPENDS+= p5-Config-Any-[0-9]*:../../devel/p5-Config-Any
BUILD_DEPENDS+= p5-FindBin-libs-[0-9]*:../../devel/p5-FindBin-libs
BUILD_DEPENDS+= p5-IO-Interactive-[0-9]*:../../devel/p5-IO-Interactive
BUILD_DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
BUILD_DEPENDS+=	p5-MooseX-Types-Path-Class-[0-9]*:../../devel/p5-MooseX-Types-Path-Class
BUILD_DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
BUILD_DEPENDS+= p5-Pod-Elemental-[0-9]*:../../textproc/p5-Pod-Elemental
BUILD_DEPENDS+= p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+= p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
BUILD_DEPENDS+= p5-Text-WagnerFischer-[0-9]*:../../textproc/p5-Text-WagnerFischer
BUILD_DEPENDS+= p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=	auto/MooseX/App/.packlist
USE_LANGUAGES=	# none

# NetBSD/amd64 6.1.4 won't give waitpid() to return, disable for the moment
# (affects only on make test)
post-patch:
	${MV} ${WRKSRC}/t/11_process.t ${WRKSRC}/t/11_process.t.orig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
