# $NetBSD: Makefile,v 1.40 2001/04/16 02:49:43 itojun Exp $
#

DISTNAME=	cvs-1.11
PKGNAME=	${DISTNAME}nb2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvshome.org/pub/${DISTNAME}/ \
		${MASTER_SITE_GNU:=cvs/}

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cvs-1.11-v6-20010413.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

BUILD_DEPENDS+=	autoconf-*:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6

.if (${OPSYS} == "SunOS")
DEPENDS+=	zlib-*:../../devel/zlib
CFLAGS+=	-I${PREFIX}/include		# zlib.h
.endif

.if defined(KERBEROS)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
CONFIGURE_ARGS+=	--with-gssapi=/usr
.endif

.if defined(RCS_LOCALID)
pre-fetch:
	@${ECHO} RCS_LOCALID is now replaced by the tag variable in CVSROOT/config.
.endif

.if ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info

post-patch:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
