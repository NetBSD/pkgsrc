# $NetBSD: Makefile,v 1.22 2017/08/16 20:45:34 wiz Exp $
#

DISTNAME=	chmlib-0.40
CATEGORIES=	devel
#MASTER_SITES=	http://morte.jedrea.com/~jedwin/projects/chmlib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://morte.jedrea.com/~jedwin/projects/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	kchm-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-io64

INSTALLATION_DIRS=	include lib

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-pthread
.endif

.include "../../mk/bsd.pkg.mk"
