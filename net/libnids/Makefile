# $NetBSD: Makefile,v 1.25 2009/12/09 11:25:52 obache Exp $
#

DISTNAME=	libnids-1.23
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.libpcap=	build

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_MESSAGE.conf=	Fixing configuration script.

INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
