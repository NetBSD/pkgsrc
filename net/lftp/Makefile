# $NetBSD: Makefile,v 1.38 2004/04/10 23:51:36 salo Exp $
#

DISTNAME=		lftp-3.0.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
			ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/old/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		michal@pasternak.w.lub.pl
HOMEPAGE=		http://lftp.yar.ru/
COMMENT=		Powerful command line ftp client

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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

INSTALLATION_DIRS=	bin lib/lftp man/man1 share/examples/lftp share/lftp

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${EGDIR}/lftp.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
