# $NetBSD: Makefile,v 1.25 2001/01/01 21:32:54 hubertf Exp $
# FreeBSD Id: Makefile,v 1.4 1997/05/22 07:53:29 tg Exp
#

DISTNAME=	wget-1.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	wget-153-v6-20001225.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

GNU_CONFIGURE=	yes
USE_LIBINTL=	yes

INFO_FILES=	wget.info

BUILD_DEFS+=    USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=        --enable-ipv6
.else
CONFIGURE_ARGS+=        --disable-ipv6
.endif

# Prevent us from running autoconf (needed due to order of
# files patched in the IPv6 patch):
post-patch:
	${TOUCH} ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
