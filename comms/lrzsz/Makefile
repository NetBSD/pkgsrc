# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:07 tv Exp $

DISTNAME=	lrzsz-0.12.20
CATEGORIES=	comms
MASTER_SITES=	http://www.ohse.de/uwe/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ohse.de/uwe/software/lrzsz.html
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol.  (unrestrictive)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.ifdef (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "Interix")
.  include "../../devel/gettext-lib/buildlink3.mk"
LOCALE_SUFFIX=		mo
.else
CONFIGURE_ARGS+=	--with-catgets
LOCALE_SUFFIX=		cat
.endif

PLIST_SUBST+=	LOCALE_SUFFIX=${LOCALE_SUFFIX}

.include "../../mk/bsd.pkg.mk"
