# $NetBSD: Makefile,v 1.3 2003/05/07 21:33:14 seb Exp $
#

DISTNAME=	wol-0.6.0
PKGREVISION=	1
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
TEXINFO_OVERRIDE=	YES

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
