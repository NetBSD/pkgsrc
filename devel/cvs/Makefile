# $NetBSD: Makefile,v 1.49 2002/07/15 01:40:02 grant Exp $
#

DISTNAME=	cvs-1.11
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://ftp.cvshome.org/${DISTNAME}/ \
		${MASTER_SITE_GNU:=non-gnu/cvs/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

GNU_CONFIGURE=	yes

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
TEXINFO_OVERRIDE=	YES

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
