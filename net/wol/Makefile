# $NetBSD: Makefile,v 1.38 2022/06/28 11:35:22 wiz Exp $

DISTNAME=	wol-0.7.1
PKGREVISION=	13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pod2man
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
