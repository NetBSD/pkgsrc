# $NetBSD: Makefile,v 1.6 2011/10/12 07:26:15 hiramatsu Exp $

DISTNAME=	CDDB-File-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDDB-File/
COMMENT=	Parses a CDDB/freedb data file
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/CDDB/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
