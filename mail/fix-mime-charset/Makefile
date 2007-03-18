# $NetBSD: Makefile,v 1.11 2007/03/18 18:56:47 wiz Exp $
#

DISTNAME=		fix-mime-charset-0.5.3
PKGREVISION=		1
CATEGORIES=		mail converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fix-mime-chr/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fix-mime-chr.sourceforge.net/
COMMENT=		Correct MIME charset type in mail headers

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes

.include "../../textproc/enca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
