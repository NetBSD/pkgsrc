# $NetBSD: Makefile,v 1.10 2004/04/25 03:20:25 minskim Exp $
#

VERS=		2.21
DISTNAME=	TermReadKey-${VERS}
PKGNAME=	p5-Term-ReadKey-${VERS}
SVR4_PKGNAME=	p5trk
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadKey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
