# $NetBSD: Makefile,v 1.49 2012/07/17 13:22:27 jperkin Exp $

DISTNAME=	t1lib-5.1.2
PKGREVISION=	6
CATEGORIES=	fonts devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for generating bitmaps from Adobe Type 1 fonts

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pax
GNU_CONFIGURE=		yes

BUILD_TARGET=	without_doc

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DATADIR=	${PREFIX}/share/${PKGBASE}

CONF_FILES=	${EGDIR}/t1lib.config.sample ${DATADIR}/t1lib.config
CONF_FILES+=	${EGDIR}/FontDataBase ${DATADIR}/FontDataBase

INSTALLATION_DIRS=	${EGDIR} ${DATADIR} share/doc

.include "options.mk"

PLIST_VARS+=	x11

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	t1lib.config.sample
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/t1lib.config.sample ${WRKSRC}

pre-build:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

post-install:
	cd ${WRKSRC};							\
	pax -rw Fonts ${DESTDIR}${DATADIR};				\
	${CHMOD} go+r ${DESTDIR}${DATADIR}/Fonts/enc/IsoLatin2.enc;	\
	pax -rw -s "/doc/${PKGBASE}/" doc ${DESTDIR}${PREFIX}/share/doc

	${INSTALL_DATA} ${WRKSRC}/t1lib.config.sample ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/examples;						\
	pax -rw FontDataBase t1example1.c t1lib.config ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
