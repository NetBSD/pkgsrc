# $NetBSD: Makefile,v 1.58 2006/09/08 19:23:01 kristerw Exp $
#

DISTNAME=	slang-1.4.9
PKGNAME=	lib${DISTNAME}
SVR4_PKGNAME=	lslan
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/ \
		http://gd.tuwien.ac.at/editors/davis/slang/v1.4/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slang/v1.4/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v1.4/ \
		ftp://ftp.plig.org/pub/slang/v1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=    	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.s-lang.org/
COMMENT=	Routines for rapid alpha-numeric terminal applications development

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DLOPEN_REQUIRE_PTHREADS=no

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/slang
	${MV} ${PREFIX}/share/doc/slang/slangdoc.html \
		${PREFIX}/share/doc/html/slang

.include "../../mk/bsd.prefs.mk"

# Debian doesn't have -ltermcap, use -lncurses instead
.if (${OPSYS} == "Linux") && (${LOWER_VENDOR} == "debian")
BUILDLINK_TRANSFORM+=	rm:-ltermcap
.  include "../../devel/ncurses/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
