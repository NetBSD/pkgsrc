# $NetBSD: Makefile,v 1.10 2009/12/15 14:46:44 wiz Exp $
#

DISTNAME=	gwaei-1.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwaei/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwaei.sourceforge.net/
COMMENT=	Japanese dictionary for GNOME
LICENSE=	gnu-gpl-v3

DEPENDS+=	rsync-[0-9]*:../../net/rsync

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config

#SUBST_CLASSES+=		perl
#SUBST_STAGE.perl=	pre-configure
#SUBST_FILES.perl=	src/kpengine/Makefile.in
#SUBST_SED.perl=		-e "s,/usr/bin/perl,${PERL5},"
#SUBST_MESSAGE.perl=	Fixing path to perl.

SUBST_CLASSES+=		rsync
SUBST_STAGE.rsync=	pre-configure
SUBST_FILES.rsync=	src/io.c
SUBST_SED.rsync=	-e "s,@RSYNC@,${LOCALBASE}/bin/rsync,"
SUBST_MESSAGE.rsync=	Fixing path to rsync.

PLIST_SRC=		PLIST
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.5
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.18.0
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
