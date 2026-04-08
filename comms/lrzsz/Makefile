# $NetBSD: Makefile,v 1.38 2026/04/08 11:44:57 tnn Exp $

DISTNAME=	lrzsz-0.12.20
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://www.ohse.de/uwe/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ohse.de/uwe/software/lrzsz.html
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol.  (unrestrictive)
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-Wno-error=implicit-int
CFLAGS+=	-Wno-error=implicit-function-declaration
CFLAGS+=	-Wno-error=incompatible-pointer-types
CPPFLAGS.Linux+=-DSTRICT_PROTOTYPES=1	# XXX glibc 2.43

.if (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" \
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
