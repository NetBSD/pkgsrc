# $NetBSD: Makefile,v 1.11 2004/02/22 03:44:01 kristerw Exp $

DISTNAME=	wol-0.7.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
INFO_FILES=		wol.info
USE_PERL5=		build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
