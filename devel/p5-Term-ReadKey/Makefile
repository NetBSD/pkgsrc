# $NetBSD: Makefile,v 1.25 2014/09/06 14:26:43 wiz Exp $

VERS=		2.32
DISTNAME=	TermReadKey-${VERS}
PKGNAME=	p5-Term-ReadKey-${VERS}
SVR4_PKGNAME=	p5trk
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Term/ReadKey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
