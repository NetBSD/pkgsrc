# $NetBSD: Makefile,v 1.35 2004/02/16 09:05:36 salo Exp $
#

DISTNAME=		lftp-2.6.12
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
			ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/old/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		michal@pasternak.w.lub.pl
HOMEPAGE=		http://lftp.yar.ru/
COMMENT=		Powerful command line ftp client

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	# uses GNU readline internal _rl_mark_modified_lines

SHLIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-modules

CONFIGURE_ENV+=		F77=${FALSE}

EGDIR=			${PREFIX}/share/examples/lftp
CONF_FILES=		${EGDIR}/lftp.conf.default ${PKG_SYSCONFDIR}/lftp.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${EGDIR}/lftp.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
