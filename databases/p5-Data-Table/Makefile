# $NetBSD: Makefile,v 1.6 2009/05/12 12:51:07 martti Exp $

DISTNAME=	Data-Table-1.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Table/
COMMENT=	Data type related to database tables, spreadsheets, etc
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Data/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
