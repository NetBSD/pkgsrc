# $NetBSD: Makefile,v 1.1.1.1 2011/10/05 22:15:48 ryoon Exp $
#

DISTNAME=	openbabel-2.3.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openbabel/}

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://openbabel.org/
COMMENT=	Chemistry file translation program
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

USE_CMAKE=	yes

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
