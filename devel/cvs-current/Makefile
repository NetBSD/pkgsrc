# $NetBSD: Makefile,v 1.7 2000/03/22 12:12:28 fredb Exp $
#

DISTNAME=       cvs-1.10.8
CATEGORIES=	devel
MASTER_SITES=   http://download.cyclic.com/pub/${DISTNAME}/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

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
.else
CONFIGURE_ARGS+=	--with-gssapi=no
.endif

.if defined(RCS_LOCALID)
CFLAGS+=	-DLOCALID=\"\\\"${RCS_LOCALID}\\\"\"
.endif

CONFIGURE_ENV+=	perl_path=${LOCALBASE}/bin/perl

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
