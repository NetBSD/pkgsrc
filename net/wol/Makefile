# $NetBSD: Makefile,v 1.1.1.1 2003/04/04 18:16:47 zuntum Exp $
#

DISTNAME=	wol-0.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
