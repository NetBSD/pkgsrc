# $NetBSD: Makefile,v 1.15 2004/04/24 22:46:10 jlam Exp $

DISTNAME=	knights-0.4.6
PKGREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=knights/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://knights.sourceforge.net/
COMMENT=	Chess interface for KDE

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/admin/ltconfig

MEINPROC=		${BUILDLINK_PREFIX.kdelibs2}/bin/meinproc
DOCDIR=			${PREFIX}/share/doc/kde/HTML/en/knights

post-build:
	cd ${WRKSRC}/doc/en; \
	${MEINPROC} --check --cache index.cache.bz2 index.docbook

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/en/index.cache.bz2 ${DOCDIR}

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
