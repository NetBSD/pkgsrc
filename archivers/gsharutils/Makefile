# $NetBSD: Makefile,v 1.19 2003/10/20 09:37:24 agc Exp $

DISTNAME=	sharutils-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		install install-man
USE_MAKEINFO=		YES
INFO_FILES=		remsync.info sharutils.info

CONFIGURE_ARGS+=	--disable-uucode

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

post-patch:
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/po/sharutils.pot

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
