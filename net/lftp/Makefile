# $NetBSD: Makefile,v 1.8 2001/02/19 14:56:22 wiz Exp $
#

DISTNAME=	lftp-2.3.8
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
