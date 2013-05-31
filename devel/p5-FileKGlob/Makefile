# $NetBSD: Makefile,v 1.24 2013/05/31 12:40:22 wiz Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
PKGREVISION=	8
SVR4_PKGNAME=	p5fkg
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expand a Unix file glob into a list of matching file names

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/File
PERL5_PACKLIST=		auto/File/KGlob/.packlist

REPLACE_PERL=	KGlob.pm KGlob2RE.pm

DIST_SUBDIR=	${PKGNAME_NOREV}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
