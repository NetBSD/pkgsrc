# $NetBSD: Makefile,v 1.9 2003/07/17 21:29:46 grant Exp $
#

DISTNAME=	buildtool-0.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable BSD-like build infrastructure

USE_BUILDLINK2=	yes
HAS_CONFIGURE=	yes

TEXINFO_REQD=		4.0
USE_MAKEINFO=		yes
USE_NEW_TEXINFO=	yes
INFO_FILES=		buildtool.info

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS=		-p ${LOCALBASE}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		SH="${SH}"

.include "../../mk/bsd.pkg.mk"
