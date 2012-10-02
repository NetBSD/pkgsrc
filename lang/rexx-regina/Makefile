# $NetBSD: Makefile,v 1.13 2012/10/02 20:11:51 asau Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	Implementation of the REXX language

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFLICTS=	rexx-imc-[0-9]*

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			sharedir=${DESTDIR}${PREFIX}/share/regina

.include "../../mk/bsd.pkg.mk"
