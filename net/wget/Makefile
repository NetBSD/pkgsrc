# $NetBSD: Makefile,v 1.21 2000/08/16 06:38:44 itojun Exp $
# FreeBSD Id: Makefile,v 1.4 1997/05/22 07:53:29 tg Exp
#

DISTNAME=	wget-1.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	wget-153-v6-20000816.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html

GNU_CONFIGURE=	yes
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

.include "../../mk/bsd.pkg.mk"
