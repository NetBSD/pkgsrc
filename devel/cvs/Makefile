# $NetBSD: Makefile,v 1.47 2002/01/11 12:47:23 skrll Exp $
#

DISTNAME=	cvs-1.11
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvshome.org/pub/${DISTNAME}/ \
		${MASTER_SITE_GNU:=cvs/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6
USE_BUILDLINK_ONLY=	yes

.if (${OPSYS} == "NetBSD")
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		cvs-1.11-v6-20020111.diff.gz
PATCH_DIST_STRIP=	-p1

.if ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.endif

.if defined(KERBEROS)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
CONFIGURE_ARGS+=	--with-gssapi=/usr
.endif

.if defined(RCS_LOCALID)
pre-fetch:
	@${ECHO} RCS_LOCALID is now replaced by the tag variable in CVSROOT/config.
.endif

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
