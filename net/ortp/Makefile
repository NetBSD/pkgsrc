# $NetBSD: Makefile,v 1.9 2015/06/08 13:43:45 joerg Exp $
#

DISTNAME=	ortp-0.16.1
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://download.savannah.nongnu.org/releases/linphone/ortp/sources/

MAINTAINER=	zul@netbsd-fr.org
HOMEPAGE=	http://www.linphone.org/index.php/eng/code_review/ortp
COMMENT=	Real-time Transport Protocol stack
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV+=	ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE+=	ortp.pc.in

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
