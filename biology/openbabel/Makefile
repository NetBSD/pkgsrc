# $NetBSD: Makefile,v 1.10 2012/10/02 17:10:37 tron Exp $
#

DISTNAME=	openbabel-2.3.0
PKGREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openbabel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openbabel.org/
COMMENT=	Chemistry file translation program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_CMAKE=	yes

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
