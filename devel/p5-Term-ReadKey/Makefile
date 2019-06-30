# $NetBSD: Makefile,v 1.36 2019/06/30 20:15:48 nia Exp $

VERS=		2.38
DISTNAME=	TermReadKey-${VERS}
PKGNAME=	p5-Term-ReadKey-${VERS}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TermReadKey
COMMENT=	Change terminal modes and perform non-blocking reads
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Term/ReadKey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
