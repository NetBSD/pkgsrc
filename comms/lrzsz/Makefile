# $NetBSD: Makefile,v 1.15 2004/02/21 08:19:57 minskim Exp $
# FreeBSD Id: Makefile,v 1.5 1997/10/10 06:53:29 obrien Exp

DISTNAME=	lrzsz-0.12.20
CATEGORIES=	comms
MASTER_SITES=	http://www.ohse.de/uwe/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ohse.de/uwe/software/lrzsz.html
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol.  (unrestrictive)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		# defined
USE_PKGLOCALEDIR=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-catgets

.include "../../mk/bsd.prefs.mk"

.ifdef (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin")
LOCALE_SUFFIX=	mo
.else
LOCALE_SUFFIX=	cat
.endif

PLIST_SUBST+=	LOCALE_SUFFIX=${LOCALE_SUFFIX}

.include "../../mk/bsd.pkg.mk"
