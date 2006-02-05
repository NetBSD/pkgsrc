# $NetBSD: Makefile,v 1.19 2006/02/05 23:09:59 joerg Exp $
#

DISTNAME=	tnef-1.3.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tnef/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://tnef.sourceforge.net/
COMMENT=	Decode MS-TNEF MIME attachments

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
