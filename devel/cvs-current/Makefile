# $NetBSD: Makefile,v 1.2 1999/08/18 09:04:17 agc Exp $
#

DISTNAME=       cvs-1.10.6
CATEGORIES=	devel
MASTER_SITES=   ftp://download.cyclic.com/pub/${DISTNAME}/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

BUILD_DEFS+=	USE_KERBEROS4 USE_KERBEROS5 RCS_LOCALID

#.if exists(/usr/lib/libkrb.a)
#CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
#.endif

.include "../../mk/bsd.prefs.mk"

.if defined(RCS_LOCALID)
CFLAGS+=	-DLOCALID=\"\\\"${RCS_LOCALID}\\\"\"
.endif

CONFIGURE_ENV+=	perl_path=${LOCALBASE}/bin/perl

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
