# $NetBSD: Makefile,v 1.3 2023/10/24 22:10:27 wiz Exp $

VER=				1.4
DISTNAME=			nsca-ng-${VER}
PKGREVISION=			2
CATEGORIES=			net
MASTER_SITES=			http://www.nsca-ng.org/download/

MAINTAINER=			timo@math.uni-bonn.de
HOMEPAGE=			https://www.nsca-ng.org/download/
COMMENT=			Send/accept passive check results to/from nagios
LICENSE=			2-clause-bsd

SUBST_CLASSES+=			config
SUBST_MESSAGE.config=		Adjust variables: VARBASE (in nsca-ng.cfg)
SUBST_FILES.config+=		etc/nsca-ng.cfg
SUBST_STAGE.config=		pre-configure
SUBST_VARS.config=		VARBASE

RCD_SCRIPTS=			nsca_ng_server
RCD_SCRIPT_SRC.nsca_ng_server=	files/nsca-ng-server.sh

EGDIR=				${PREFIX}/share/examples/nsca-ng
CONF_FILES=			${EGDIR}/nsca-ng.cfg ${PKG_SYSCONFDIR}/nsca-ng.cfg

INSTALLATION_DIRS+=		${EGDIR}
INSTALL_MAKE_FLAGS+=		sysconfdir=${EGDIR}

GNU_CONFIGURE=			yes
CONFIGURE_ARGS+=		--sysconfdir=${PKG_SYSCONFDIR} --enable-server=yes --enable-client=yes --localstatedir=/var/spool

# Not available in OpenSSL 1.1.x
CONFIGURE_ENV+=	ac_cv_lib_ssl_SSL_library_init=yes

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
