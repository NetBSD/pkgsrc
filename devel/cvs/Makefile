# $NetBSD: Makefile,v 1.69 2003/12/12 22:05:55 wiz Exp $
#

DISTNAME=	cvs-1.11.10
CATEGORIES=	devel
MASTER_SITES=	http://www.cvshome.org/files/19/10/ \
		http://ftp.cvshome.org/release/stable/${DISTNAME}/
#		${MASTER_SITE_GNU:=non-gnu/cvs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6
USE_BUILDLINK2=		yes

.if defined(USE_INET6) && ${USE_INET6} == "YES" && 	\
	empty(MACHINE_PLATFORM:MSunOS-5.[89]-*) && empty(MACHINE_PLATFORM:MLinux-*)
CONFIGURE_ARGS+=	--enable-ipv6
PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		cvs-1.11.10-v6-20031205.diff.gz
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
USE_MAKEINFO=		yes
TEXINFO_REQD?=		4.0

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
