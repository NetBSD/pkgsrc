# $NetBSD: Makefile,v 1.8 2003/06/02 01:20:22 jschauma Exp $
#

VERS=		2.21
DISTNAME=	TermReadKey-${VERS}
PKGNAME=	p5-Term-ReadKey-${VERS}
SVR4_PKGNAME=	p5trk
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadKey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
