# $NetBSD: Makefile,v 1.28.2.1 2003/12/14 20:34:57 agc Exp $
#

DISTNAME=		lftp-2.6.10
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
			ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/old/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		michal@pasternak.w.lub.pl
HOMEPAGE=		http://lftp.yar.ru/
COMMENT=		Powerful command line ftp client

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	# uses GNU readline internal _rl_mark_modified_lines

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-modules

CONFIGURE_ENV+=		F77=${FALSE}

EGDIR=			${PREFIX}/share/examples/lftp
CONF_FILES=		${EGDIR}/lftp.conf.default ${PKG_SYSCONFDIR}/lftp.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${EGDIR}/lftp.conf.default

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
