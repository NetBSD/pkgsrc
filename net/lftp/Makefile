# $NetBSD: Makefile,v 1.9 2001/03/24 19:21:36 zuntum Exp $
#

DISTNAME=	lftp-2.3.9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/\
		${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	powerful command line ftp client

DEPENDS+=	readline>=4.1:../../devel/readline

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
