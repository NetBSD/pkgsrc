# $NetBSD: Makefile,v 1.27 2000/05/21 15:27:29 kim Exp $
#

DISTNAME=       cvs-1.10
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cvshome.org/pub/${DISTNAME}/ \
		${MASTER_SITE_GNU:=cvs/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cvshome.org/

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

BUILD_DEFS+=	RCS_LOCALID

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.else
CONFIGURE_ARGS+=	--with-krb4=no
.endif

.if defined(KERBEROS) && ${KERBEROS} == 5
USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-gssapi
CFLAGS+=		-I/usr/include/krb5		# krb5.h
.else
CONFIGURE_ARGS+=	--with-gssapi=no
.endif

.if defined(RCS_LOCALID)
CFLAGS+=	-DLOCALID=\"\\\"${RCS_LOCALID}\\\"\"
.endif

CONFIGURE_ENV+=	perl_path=${LOCALBASE}/bin/perl

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
