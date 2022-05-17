# $NetBSD: Makefile,v 1.16 2022/05/17 12:08:25 wiz Exp $

DISTNAME=	ortp-0.16.1
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://download.savannah.nongnu.org/releases/linphone/ortp/sources/

MAINTAINER=	zul@netbsd-fr.org
HOMEPAGE=	https://www.linphone.org/technical-corner/ortp
COMMENT=	Real-time Transport Protocol stack
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_LIBTOOL=	yes

CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE+=	ortp.pc.in

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -DBSD_COMP
LDFLAGS.SunOS+=	-lsocket -lnsl

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
