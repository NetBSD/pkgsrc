# $NetBSD: Makefile,v 1.7 2013/06/01 22:42:49 dholland Exp $

DISTNAME=	kernel_ppp_mppe-0.0.4-src
PKGNAME=	mppe-lkm-0.0.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poptop/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NetBSD kernel module for MPPE compression with PPP

PKG_DESTDIR_SUPPORT=	destdir

NO_CONFIGURE=	yes

ONLY_FOR_PLATFORM=	NetBSD-[12345]*-*
MAKE_ENV+=	KMODDIR=${PREFIX}/lkm
WRKSRC=		${WRKDIR}/mppe-lkm
KPM_SRC=	${WRKDIR}/${DISTNAME:C/-src$//}

INSTALLATION_DIRS=	lkm

post-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}
	@${CHMOD} -R u+w ${KPM_SRC}
	@${CP} -p ${KPM_SRC}/ppp-comp-local.h ${KPM_SRC}/ppp_mppe_compress.c \
		${WRKSRC}

.include "../../mk/bsd.pkg.mk"
