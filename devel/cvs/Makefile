# $NetBSD: Makefile,v 1.60 2003/03/18 15:29:48 grant Exp $
#

DISTNAME=	cvs-1.11.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.cvshome.org/${DISTNAME}/ \
		${MASTER_SITE_GNU:=non-gnu/cvs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6
USE_BUILDLINK2=		yes

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		cvs-1.11.4-v6-20030102.diff.gz
PATCH_DIST_STRIP=	-p1
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(KERBEROS)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
CONFIGURE_ARGS+=	--with-gssapi=/usr
CPPFLAGS+=		-I/usr/include/krb5
.  if ${OPSYS} == "Darwin"
LDFLAGS+=		-framework Kerberos
.  endif
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif

.if defined(RCS_LOCALID)
pre-fetch:
	@${ECHO} RCS_LOCALID is now replaced by the tag variable in CVSROOT/config.
.endif

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info
TEXINFO_REQD?=		4.0
TEXINFO_OVERRIDE=	YES

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
