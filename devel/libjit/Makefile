# $NetBSD: Makefile,v 1.15 2011/12/22 00:26:02 joerg Exp $
#

DISTNAME=	libjit-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/libjit-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex yacc makeinfo
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	ac_cv_header_tgmath_h=no
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
