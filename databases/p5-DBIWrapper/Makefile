# $NetBSD: Makefile,v 1.1.1.1 2004/07/08 19:23:08 erh Exp $
#

DISTNAME=	libdbiwrapper-perl-${VERSION}
PKGNAME=	p5-DBIWrapper-${VERSION}
SVR4_PKGNAME=	p5dbw
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbiwrapper/}

MAINTAINER=	erh@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/dbiwrapper/
COMMENT=	Perl extension for generic DBI database access

DEPENDS+=	p5-XML-LibXML>=1.57:../../textproc/p5-XML-LibXML

VERSION=	0.20

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIWrapper/.packlist

BUILDLINK_DEPENDS.p5-DBI+=	p5-DBI>=1.37

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
