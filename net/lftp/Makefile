# $NetBSD: Makefile,v 1.15.2.2 2002/07/01 17:45:00 jlam Exp $

DISTNAME=	lftp-2.5.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michal@pasternak.w.lub.pl
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	powerful command line ftp client

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--sysconfdir=${PKG_SYSCONFDIR}
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# uses GNU readline internal variables (_rl_mark_modified_lines)
USE_GNU_READLINE=	YES

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/lftp
CONF_FILES=	${EGDIR}/lftp.conf ${PKG_SYSCONFDIR}/lftp.conf
OWN_DIRS=	${PREFIX}/lib/lftp
OWN_DIRS+=	${PREFIX}/lib/lftp/${PKG_VERSION}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lftp
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/share/examples/lftp

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
