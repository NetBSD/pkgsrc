# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:11 tv Exp $
#

DISTNAME=	bump_scope-0.0.3
PKGNAME=	xmms-bump-scope-0.0.3
PKGREVISION=	3
CATEGORIES=	xmms audio
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	Moving light embossing oscilloscope

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

MAKE_ENV+=	plugindir=${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
