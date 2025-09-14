# $NetBSD: Makefile,v 1.34 2025/09/14 13:08:13 leot Exp $
#

DISTNAME=	rlwrap-0.47.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hanslub42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/hanslub42/rlwrap
COMMENT=	Provides command line editing and history for other commands
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		autoreconf autoconf automake

CONFIGURE_ARGS+=	--without-libptytty

TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "options.mk"

# Do not install filters to avoid Perl and Python dependencies.
# Filter provided by default are used to exercise rlwrap, not to be practical.
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/rlwrap/filters
	${RM} -rf ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

BUILDLINK_API_DEPENDS.readline+=readline>=4.2
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
