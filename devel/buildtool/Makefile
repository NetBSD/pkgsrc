# $NetBSD: Makefile,v 1.1.1.1 2002/10/21 08:16:06 agc Exp $
#

DISTNAME=	buildtool-0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Build infrastructure for source packages

INFO_FILES+=	buildtool.info

do-configure:
	cd ${WRKSRC} && ./configure -p ${LOCALBASE}

.include "../../mk/texinfo.mk"

.include "../../mk/bsd.pkg.mk"
