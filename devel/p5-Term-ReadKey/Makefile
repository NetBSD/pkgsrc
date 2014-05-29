# $NetBSD: Makefile,v 1.24 2014/05/29 23:36:19 wiz Exp $
#

VERS=		2.30
DISTNAME=	TermReadKey-${VERS}
PKGNAME=	p5-Term-ReadKey-${VERS}
PKGREVISION=	7
SVR4_PKGNAME=	p5trk
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Term/ReadKey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
