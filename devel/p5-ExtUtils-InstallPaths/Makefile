# $NetBSD: Makefile,v 1.1 2013/07/03 07:07:52 sno Exp $

DISTNAME=	ExtUtils-InstallPaths-0.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-InstallPaths/
COMMENT=	Build.PL install path logic made easy
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Config>=0.002:../../devel/p5-ExtUtils-Config

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/InstallPaths/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
