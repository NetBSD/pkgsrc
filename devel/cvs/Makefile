# $NetBSD: Makefile,v 1.15 1998/10/11 17:37:59 frueauf Exp $
#

DISTNAME=       cvs-1.10
CATEGORIES=	devel
MASTER_SITES=   ftp://download.cyclic.com/pub/${DISTNAME}/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

CONFLICTS=	cvs-1.9 cvs-1.9.26 cvs-1.9.27 cvs-1.9.28 cvs-1.9.29 cvs-1.9.30

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.endif

.include "../../mk/bsd.prefs.mk"

.if defined(RCS_LOCALID)
CFLAGS+=	-DLOCALID=\"\\\"${RCS_LOCALID}\\\"\"
.endif

CONFIGURE_ENV+=	perl_path=${LOCALBASE}/bin/perl

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
