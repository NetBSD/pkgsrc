# $NetBSD: Makefile,v 1.2 2000/08/27 07:11:06 jlam Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
WRKSRC=		${WRKDIR}/File
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/KGlob/.packlist

DIST_SUBDIR=	${PKGNAME}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
