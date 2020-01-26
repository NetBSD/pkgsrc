# $NetBSD: Makefile,v 1.32 2020/01/26 17:30:50 rillig Exp $

DISTNAME=	lrzsz-0.12.20
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.ohse.de/uwe/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ohse.de/uwe/software/lrzsz.html
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol.  (unrestrictive)

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "Interix" \
	|| ${OPSYS} == "Linux" || ${OPSYS} == "Haiku")
BROKEN_GETTEXT_DETECTION=yes
.  include "../../devel/gettext-lib/buildlink3.mk"
LOCALE_SUFFIX=		mo
.else
CONFIGURE_ARGS+=	--with-catgets
LOCALE_SUFFIX=		cat
.endif

PLIST_SUBST+=	LOCALE_SUFFIX=${LOCALE_SUFFIX:Q}

.include "../../mk/bsd.pkg.mk"
