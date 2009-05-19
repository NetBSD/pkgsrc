# $NetBSD: Makefile,v 1.31 2009/05/19 08:59:20 wiz Exp $
#

DISTNAME=	GNUMail-1.2.0pre3
PKGREVISION=	1
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/GNUMail
NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile

FIX_GNUSTEP_INSTALLATION_DIR= yes
.for _dir_ in Account Advanced Clock Colors Compose Face Filtering	\
	Fonts Import MIME PGP Receiving Sending Viewing
SUBST_FILES.gnustep_installation_dir+=	Bundles/${_dir_}/GNUmakefile
.endfor

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
