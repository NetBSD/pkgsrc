# $NetBSD: Makefile,v 1.11 2001/06/28 13:35:31 wiz Exp $
#

DISTNAME=	lftp-2.3.9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/\
		${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	powerful command line ftp client

GNU_CONFIGURE=		YES
# uses GNU readline internal variables (_rl_mark_modified_lines)
USE_GNU_READLINE=	YES
USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

USE_LIBINTL=		YES

.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
