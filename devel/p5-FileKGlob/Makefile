# $NetBSD: Makefile,v 1.1.1.1 1999/05/12 20:47:13 bad Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
WRKSRC=		${WRKDIR}/File
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
