# $NetBSD: Makefile,v 1.16 2005/02/05 14:54:14 heinz Exp $
#

DISTNAME=	tnef-1.3.1
PKGREVISION=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tnef/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://tnef.sourceforge.net/
COMMENT=	Decode MS-TNEF MIME attachments

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
