# $NetBSD: Makefile,v 1.19 2008/10/19 19:17:54 he Exp $
#

DISTNAME=	FileKGlob
PKGNAME=	p5-FileKGlob-1.2
PKGREVISION=	4
SVR4_PKGNAME=	p5fkg
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expand a Unix file glob into a list of matching file names

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/File
PERL5_PACKLIST=		auto/File/KGlob/.packlist

REPLACE_PERL=	KGlob.pm KGlob2RE.pm

DIST_SUBDIR=	${PKGNAME_NOREV}

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
