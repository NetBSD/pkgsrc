# $NetBSD: Makefile,v 1.2 2001/12/02 18:53:23 jlam Exp $

DISTNAME=	knights-0.4.6
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=knights/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://knights.sourceforge.net/
COMMENT=	chess interface for KDE

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/admin/ltconfig

AUTOMAKE_OVERRIDE=	YES
MEINPROC=		${BUILDLINK_PREFIX.kdelibs2}/bin/meinproc
DOCDIR=			${PREFIX}/share/doc/kde/HTML/en/knights

post-build:
	cd ${WRKSRC}/doc/en; \
	${MEINPROC} --check --cache index.cache.bz2 index.docbook

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/en/index.cache.bz2 ${DOCDIR}

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
