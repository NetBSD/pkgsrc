# $NetBSD: Makefile,v 1.7 2003/06/02 01:20:31 jschauma Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
SVR4_PKGNAME=	p5fkg
WRKSRC=		${WRKDIR}/File
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Expand a Unix file glob into a list of matching file names

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/KGlob/.packlist

DIST_SUBDIR=	${PKGNAME}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
