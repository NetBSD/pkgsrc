# $NetBSD: Makefile,v 1.3 1999/09/13 14:01:29 kim Exp $
#

DISTNAME=       cvs-1.10.6
CATEGORIES=	devel
MASTER_SITES=   ftp://download.cyclic.com/pub/${DISTNAME}/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

BUILD_DEFS+=	USE_KERBEROS4 USE_KERBEROS5 RCS_LOCALID

.include "../../mk/bsd.prefs.mk"

.if defined(USE_KERBEROS4)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.else
CONFIGURE_ARGS+=	--with-krb4=no
.endif

.if defined(USE_KERBEROS5)
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
