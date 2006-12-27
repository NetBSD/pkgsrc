# $NetBSD: Makefile,v 1.53 2006/12/27 13:37:38 joerg Exp $

DISTNAME=       xpm-3.4k
PKGREVISION=	7
CATEGORIES=	graphics x11
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/xpm/ \
		${MASTER_SITE_XCONTRIB:=libraries/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://koala.ilog.fr/lehors/xpm.html
COMMENT=	The X Pixmap library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		libXpm-[0-9]*

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -f libXpm.so.4.11 libXpm.so.4
.endif

.if !empty(LOWER_OPSYS:Mirix5*)
SUBST_CLASSES+=	sodots
SUBST_STAGE.sodots=	post-configure
SUBST_FILES.sodots=	lib/Makefile
SUBST_SED.sodots=	-e 's,\.so$$(SOXPMLIBREV),.so.$$(SOXPMLIBREV),g'
# needs snprintf()
. include "../../pkgtools/libnbcompat/buildlink3.mk"
IMAKEOPTS+=	-DExtraLibraries=${BUILDLINK_LDADD.libnbcompat:Q}
IMAKEOPTS+=	-DInstallCmd=${INSTALL:Q}

post-configure:
	${MKDIR} ${WRKSRC}/usrlib

post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -sf libXpm.so.4.11 libXpm.so.4
	
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
