# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 23:56:38 hubertf Exp $
#

DISTNAME=	bump_scope-0.0.3
PKGNAME=	xmms-bump-scope-0.0.3
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
