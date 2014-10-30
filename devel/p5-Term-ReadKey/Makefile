# $NetBSD: Makefile,v 1.28 2014/10/30 13:48:50 wiz Exp $

VERS=		2.32
DISTNAME=	TermReadKey-${VERS}
PKGNAME=	p5-Term-ReadKey-${VERS}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Term/ReadKey/.packlist
MAKE_JOBS_SAFE=		no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
