# $NetBSD: Makefile,v 1.27 2025/11/17 11:01:04 wiz Exp $
#

DISTNAME=		fix-mime-charset-0.5.3
PKGREVISION=		11
CATEGORIES=		mail converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fix-mime-chr/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fix-mime-chr.sourceforge.net/
COMMENT=		Correct MIME charset type in mail headers

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl pkg-config pod2man
GNU_CONFIGURE=		yes

.include "../../textproc/enca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
