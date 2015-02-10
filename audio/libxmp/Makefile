# $NetBSD: Makefile,v 1.8 2015/02/10 03:30:03 rxg Exp $

DISTNAME=	libxmp-4.3.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin lib
INSTALL_MAKE_FLAGS+=	INSTALL=${INSTALL:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_c_flag_f_visibility_hidden=no
.endif

.include "../../mk/bsd.pkg.mk"
