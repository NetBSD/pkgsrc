# $NetBSD: Makefile,v 1.42 2001/12/04 06:15:00 jlam Exp $

DISTNAME=	wget-1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	wget-17-v6-20010716a.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK_ONLY=	YES

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

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

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
