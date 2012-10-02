# $NetBSD: Makefile,v 1.14 2012/10/02 21:25:29 asau Exp $
#

DISTNAME=	libdbiwrapper-perl-${VERSION}
PKGNAME=	p5-DBIWrapper-${VERSION}
PKGREVISION=	7
SVR4_PKGNAME=	p5dbw
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbiwrapper/}

MAINTAINER=	erh@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dbiwrapper/
COMMENT=	Perl extension for generic DBI database access

DEPENDS+=	p5-XML-LibXML>=1.57:../../textproc/p5-XML-LibXML

VERSION=	0.20

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DBIWrapper/.packlist

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.37

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
