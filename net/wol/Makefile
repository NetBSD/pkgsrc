# $NetBSD: Makefile,v 1.40 2025/11/17 11:01:18 wiz Exp $

DISTNAME=	wol-0.7.1
PKGREVISION=	13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pod2man
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
