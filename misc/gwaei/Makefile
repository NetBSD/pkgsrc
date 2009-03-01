# $NetBSD: Makefile,v 1.4 2009/03/01 15:13:21 wiz Exp $
#

DISTNAME=	gwaei-0.15.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwaei/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwaei.sourceforge.net/
COMMENT=	Japanese dictionary for GNOME

DEPENDS+=	rsync-[0-9]*:../../net/rsync

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS=		xdg-1.4 gnome2-1.6
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config

GCONF_SCHEMAS=		gwaei.schemas

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	src/kpengine/Makefile.in
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PERL5},"
SUBST_MESSAGE.perl=	Fixing path to perl.

SUBST_CLASSES+=		rsync
SUBST_STAGE.rsync=	pre-configure
SUBST_FILES.rsync=	src/io.c
SUBST_SED.rsync=	-e "s,@RSYNC@,${LOCALBASE}/bin/rsync,"
SUBST_MESSAGE.rsync=	Fixing path to rsync.

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/schemas/gwaei.schemas \
		${DESTDIR}${PREFIX}/share/gconf/schemas/

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.22.0
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.22.0
.include "../../devel/libgnome/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsexy+=		libsexy>=0.1.11
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.18.0
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
