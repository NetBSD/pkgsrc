# $NetBSD: Makefile,v 1.14 2002/04/22 15:22:23 tron Exp $

DISTNAME=	lftp-2.5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/\
		${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michal@pasternak.w.lub.pl
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	powerful command line ftp client

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR} \
			--sysconfdir=${PKG_SYSCONFDIR}
USE_BUILDLINK_ONLY=	YES
# uses GNU readline internal variables (_rl_mark_modified_lines)
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lftp
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/share/examples/lftp

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
