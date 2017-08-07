# $NetBSD: Makefile,v 1.3 2017/08/07 09:42:32 jlam Exp $
#

DISTNAME=	mcollective-2.1.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/mcollective/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://puppetlabs.com/mcollective/
COMMENT=	Framework to build server orchestration
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-stomp>=1.2.5:../../devel/ruby-stomp

NO_BUILD=	yes
USE_TOOLS+=	pax

RCD_SCRIPTS=	mcollectived

REPLACE_RUBY=	bin/mcollectived bin/mco bin/mc-call-agent	\
		lib/mcollective/vendor/json/*/*			\
		lib/mcollective/vendor/json/*

EGDIR=			${PREFIX}/share/examples/mcollective

INSTALLATION_DIRS=	bin sbin share/doc/mcollective share/mcollective
INSTALLATION_DIRS+=	${RUBY_VENDORLIB}/mcollective
INSTALLATION_DIRS+=	${EGDIR}

PKG_SYSCONFSUBDIR=	mcollective
OWN_DIRS=		${PKG_SYSCONFDIR}/ssl

CONF_FILES+=		${EGDIR}/server.cfg.dist		\
			${PKG_SYSCONFDIR}/server.cfg
CONF_FILES+=		${EGDIR}/client.cfg.dist		\
			${PKG_SYSCONFDIR}/client.cfg

SUBST_CLASSES+=		confpath
SUBST_FILES.confpath=	${WRKSRC}/bin/mcollectived		\
			${WRKSRC}/etc/server.cfg.dist		\
			${WRKSRC}/etc/client.cfg.dist		\
			${WRKSRC}/lib/mcollective/config.rb	\
			${WRKSRC}/lib/mcollective/util.rb	\
			${WRKSRC}/lib/mcollective/rpc.rb
SUBST_SED.confpath=	-e "s,/etc/mcollective,${PKG_SYSCONFDIR},"
SUBST_STAGE.confpath=	post-patch

SUBST_CLASSES+=		sharepath
SUBST_FILES.sharepath=	${WRKSRC}/etc/server.cfg.dist		\
			${WRKSRC}/etc/client.cfg.dist
SUBST_SED.sharepath=	-e "s,/usr/libexec/mcollective,${PREFIX}/share,"
SUBST_STAGE.sharepath=	post-patch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mcollectived ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mco ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mc-call-agent ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA}	${WRKSRC}/etc/server.cfg.dist		\
		${DESTDIR}${EGDIR}/server.cfg.dist
	${INSTALL_DATA}	${WRKSRC}/etc/client.cfg.dist		\
		${DESTDIR}${EGDIR}/client.cfg.dist

	cd ${WRKSRC}/plugins/mcollective && 			\
		${PAX} -wr * ${DESTDIR}${PREFIX}/share/mcollective

	cd ${WRKSRC}/doc && 					\
		${PAX} -wr * ${DESTDIR}${PREFIX}/share/doc/mcollective

	cd ${WRKSRC}/lib &&					\
		${PAX} -wr * ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
