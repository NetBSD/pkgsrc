# $NetBSD: Makefile,v 1.4 2000/11/05 17:18:15 wiz Exp $
#

DISTNAME=	lftp-2.3.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/\
		${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ftp.yars.free.net/projects/lftp/

DEPENDS+=	readline>=4.1:../../devel/readline

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

USE_LIBINTL=	YES
CPPFLAGS+=	-I${LOCALBASE}/include			# for libintl.h
# if we have /usr/lib/libintl.a, we don't really need -L
INTLLIBS=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" INTLLIBS="${INTLLIBS}"
CONFIGURE_ARGS+=	--without-included-gettext

.include "../../mk/bsd.pkg.mk"
