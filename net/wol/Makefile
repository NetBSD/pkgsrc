# $NetBSD: Makefile,v 1.6 2003/08/09 11:16:23 seb Exp $
#

DISTNAME=	wol-0.6.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES
USE_PKGLOCALEDIR=	YES
INFO_FILES=		wol.info

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
