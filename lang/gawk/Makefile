# $NetBSD: Makefile,v 1.22 2004/04/25 07:15:51 snj Exp $
#

DISTNAME=	gawk-3.1.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk

CONFLICTS=	ja-gawk-[0-9]*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check

INFO_FILES=	gawk.info gawkinet.info

MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		GAWK_ENABLE_PORTALS
.if ${GAWK_ENABLE_PORTALS} == "YES"
CONFIGURE_ARGS+=	--enable-portals
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
