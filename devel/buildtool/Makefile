# $NetBSD: Makefile,v 1.10 2003/07/24 10:12:30 jmmv Exp $
#

DISTNAME=	buildtool-0.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable BSD-like build infrastructure

USE_BUILDLINK2=	yes
HAS_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS=		-p ${LOCALBASE}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		M4="${M4}"
CONFIGURE_ENV+=		SH="${SH}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/buildtool-0/pkgflags

.include "../../mk/bsd.pkg.mk"
