# $NetBSD: Makefile,v 1.80 2004/10/03 00:13:25 tv Exp $
#

DISTNAME=	cvs-1.11.17
PKGREVISION=	2
CATEGORIES=	devel
# (SSL) download URL according to http://www.cvshome.org/ is
# https://ccvs.cvshome.org/files/documents/19/191/cvs-1.11.17.tar.bz2
MASTER_SITES=	http://musthave.sunbase.org/progs/ccvs/${DISTNAME}/ \
		${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS]) && \
    empty(MACHINE_PLATFORM:MSunOS-5.[89]-*) && \
    empty(MACHINE_PLATFORM:MLinux-*)
CONFIGURE_ARGS+=	--enable-ipv6
PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		cvs-1.11.17-v6-20040610.diff.gz
PATCH_DIST_STRIP=	-p1
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(KERBEROS)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-encryption
CONFIGURE_ARGS+=	--with-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-krb4=${KRB5BASE}
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
USE_MAKEINFO=		yes
TEXINFO_REQD?=		4.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
