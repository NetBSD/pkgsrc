# $NetBSD: Makefile,v 1.13 2001/10/03 14:37:13 wiz Exp $
#

DISTNAME=	lftp-2.4.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/\
		${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	powerful command line ftp client

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
USE_BUILDLINK_ONLY=	YES
# uses GNU readline internal variables (_rl_mark_modified_lines)
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# package seems to create some unneeded empty directories
post-install:
	${RMDIR} ${PREFIX}/lib/lftp/2.4.4 ${PREFIX}/lib/lftp

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
