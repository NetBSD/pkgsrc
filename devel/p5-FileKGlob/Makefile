# $NetBSD: Makefile,v 1.12 2004/12/22 05:17:45 minskim Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
SVR4_PKGNAME=	p5fkg
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Expand a Unix file glob into a list of matching file names

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/File
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/KGlob/.packlist

DIST_SUBDIR=	${PKGNAME_NOREV}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
