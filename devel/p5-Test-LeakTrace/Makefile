# $NetBSD: Makefile,v 1.11 2015/02/17 06:36:14 mef Exp $

DISTNAME=	Test-LeakTrace-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-LeakTrace/
COMMENT=	Perl 5 module to trace memory leaks
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/LeakTrace/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
