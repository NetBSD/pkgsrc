# $NetBSD: Makefile,v 1.2 2002/11/30 15:01:06 jmmv Exp $
#

DISTNAME=	buildtool-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable BSD-like build infrastructure

USE_BUILDLINK2=	yes

TEXINFO_REQD=	4.0
INFO_FILES=	buildtool.info

PKG_SYSCONFSUBDIR=	buildtool

do-configure:
	@cd ${WRKSRC} && ${CONFIGURE_ENV} ./configure -p ${LOCALBASE} \
	    -c ${PKG_SYSCONFDIR}

.include "../../mk/texinfo.mk"

.include "../../mk/bsd.pkg.mk"
