# $NetBSD: Makefile,v 1.4 2003/01/09 19:20:18 jmmv Exp $
#

DISTNAME=	buildtool-0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable BSD-like build infrastructure

USE_BUILDLINK2=	yes
HAS_CONFIGURE=	yes

TEXINFO_REQD=	4.0
INFO_FILES=	buildtool.info

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS=		-p ${LOCALBASE}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}

.include "../../mk/texinfo.mk"

.include "../../mk/bsd.pkg.mk"
