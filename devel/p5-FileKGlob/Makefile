# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:16 veego Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
SVR4_PKGNAME=	p5fkg
WRKSRC=		${WRKDIR}/File
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Expand a Unix file glob into a list of matching file names

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/KGlob/.packlist

DIST_SUBDIR=	${PKGNAME}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
