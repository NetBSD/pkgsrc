# $NetBSD: Makefile,v 1.62 2009/10/14 20:06:41 zafer Exp $

DISTNAME=	xpm-3.4k
PKGREVISION=	7
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=libraries/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://koala.ilog.fr/lehors/xpm.html
COMMENT=	The X Pixmap library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		libXpm-[0-9]*

USE_FEATURES=	snprintf
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || !empty(MACHINE_PLATFORM:MIRIX-5*)
post-install:
	cd ${PREFIX}/lib && \
	rm -f libXpm.so.4 && \
	ln -s libXpm.so.4.11 libXpm.so.4
.endif

.if ${OPSYS} == "IRIX"
SUBST_CLASSES+=		sodots
SUBST_STAGE.sodots=	post-configure
SUBST_FILES.sodots=	lib/Makefile
SUBST_SED.sodots=	-e 's,\.so$$(SOXPMLIBREV),.so.$$(SOXPMLIBREV),g'

IMAKEOPTS+=	-DExtraLibraries=${LIBS:Q}
IMAKEOPTS+=	-DInstallCmd=${INSTALL:Q}

post-configure:
	${MKDIR} ${WRKSRC}/usrlib
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
