# $NetBSD: Makefile,v 1.19 2009/05/20 00:58:26 wiz Exp $

DISTNAME=	socat-1.7.0.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
ONLY_FOR_COMPILER=	gcc	# uses -Werror in the configure script

CONFIGURE_ARGS+=	--disable-libwrap
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	doc/socat.1
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

SUBST_CLASSES+=		makefile
SUBST_MESSAGE.makefile=	Fixing Makefile CCOPTS.
SUBST_STAGE.makefile=	post-patch
SUBST_FILES.makefile=	Makefile.in
SUBST_SED.makefile=	-e '/CCOPTS/ s/-Wall -Wno-parentheses//'

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
