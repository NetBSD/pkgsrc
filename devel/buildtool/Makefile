# $NetBSD: Makefile,v 1.3 2002/12/15 17:22:37 jmmv Exp $
#

DISTNAME=	buildtool-0.8
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
