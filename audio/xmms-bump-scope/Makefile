# $NetBSD: Makefile,v 1.3 2003/05/05 19:05:05 jmmv Exp $
#

DISTNAME=	bump_scope-0.0.3
PKGNAME=	xmms-bump-scope-0.0.3
PKGREVISION=	1
CATEGORIES=	xmms audio
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	Moving light embossing occiliscope

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

MAKE_ENV+=	plugindir=${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
