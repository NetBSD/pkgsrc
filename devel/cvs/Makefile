# $NetBSD: Makefile,v 1.18 1999/01/19 01:04:44 tv Exp $
#

DISTNAME=       cvs-1.10
CATEGORIES=	devel
MASTER_SITES=   ftp://download.cyclic.com/pub/${DISTNAME}/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

CONFLICTS=	cvs-1.9* cvs-1.10

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
