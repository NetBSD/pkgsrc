# $NetBSD: Makefile,v 1.5 2001/10/24 22:10:48 jlam Exp $

DISTNAME=	kyahoo-0.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kyahoo/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://kyahoo.sourceforge.net/
COMMENT=	Yahoo! client for KDE

USE_BUILDLINK_ONLY=	YES

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ARGS+=	--with-libyahoo=${BUILDLINK_DIR}

# Pass USER_LDFLAGS through MAKE_ENV as there doesn't seem to be a reliable
# way to stop the configure script from running again during the build step,
# and we need USER_LDFLAGS to be set to LDFLAGS by the configure script in
# accordance with the buildlink strategy outlined in kde2/Makefile.part2.
#
MAKE_ENV+=		USER_LDFLAGS="${LDFLAGS}"

pre-build:
	${CHMOD} +x ${WRKSRC}/missing

.include "../../chat/libyahoo/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
