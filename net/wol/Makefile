# $NetBSD: Makefile,v 1.9 2004/02/14 17:57:25 uebayasi Exp $
#

DISTNAME=	wol-0.7.0
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
