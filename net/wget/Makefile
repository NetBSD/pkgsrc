# $NetBSD: Makefile,v 1.49 2002/09/18 19:51:55 tron Exp $

DISTNAME=	wget-1.7
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	wget-17-v6-20010716a.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

USE_PERL5=	build

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK2=		YES

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

INFO_FILES=	wget.info

BUILD_DEFS+=    USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if (${OPSYS} != SunOS) && defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=        --enable-ipv6
.else
CONFIGURE_ARGS+=        --disable-ipv6
.endif

WGET_USE_SSL?=	YES

.if ${WGET_USE_SSL} == YES
.include "../../security/openssl/buildlink2.mk"
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}
.endif

CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
