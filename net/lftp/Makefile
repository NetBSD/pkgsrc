# $NetBSD: Makefile,v 1.28 2003/11/08 06:31:58 xtraeme Exp $
#

DISTNAME=	lftp-2.6.8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/old/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michal@pasternak.w.lub.pl
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	Powerful command line ftp client

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GNU_READLINE=	# uses GNU readline internal _rl_mark_modified_lines
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-modules

CONFIGURE_ENV+=		F77=${FALSE}

CONF_FILES=	${PREFIX}/share/examples/lftp/lftp.conf	\
		${PKG_SYSCONFDIR}/lftp.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lftp
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/share/examples/lftp

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
