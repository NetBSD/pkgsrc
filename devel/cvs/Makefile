# $NetBSD: Makefile,v 1.21 1999/08/17 19:02:52 thorpej Exp $
#

DISTNAME=       cvs-1.10
CATEGORIES=	devel
MASTER_SITES=   ftp://download.cyclic.com/pub/${DISTNAME}/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

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
