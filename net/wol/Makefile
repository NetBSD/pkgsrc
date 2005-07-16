# $NetBSD: Makefile,v 1.17 2005/07/16 01:19:17 jlam Exp $

DISTNAME=	wol-0.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_PKGLOCALEDIR=	yes
INFO_FILES=		wol.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
