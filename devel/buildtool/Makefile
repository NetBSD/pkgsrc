# $NetBSD: Makefile,v 1.7 2003/04/12 10:14:26 jmmv Exp $
#

DISTNAME=	buildtool-0.11
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
