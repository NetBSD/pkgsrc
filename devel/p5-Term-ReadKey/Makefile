# $NetBSD: Makefile,v 1.4 2001/11/26 06:49:54 jlam Exp $
#

DISTNAME=	TermReadKey-2.14
PKGNAME=	p5-Term-ReadKey-2.14
SVR4_PKGNAME=	p5trk
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadKey/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
