# $NetBSD: Makefile,v 1.8 2004/01/24 14:50:06 grant Exp $
#

DISTNAME=	wol-0.6.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_GNU_GETTEXT=	YES
USE_PKGLOCALEDIR=	YES
INFO_FILES=		wol.info

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
