# $NetBSD: Makefile,v 1.33 2002/06/20 19:28:25 jlam Exp $

PKGNAME=	coda-client-${DIST_VERS}
COMMENT=	client programs for a replicated high-performance network file system

USE_BUILDLINK_ONLY=	yes

.include "../../net/coda5_server/Makefile.common"

ALL_TARGET=		coda
INSTALL_TARGET=		client-install
INSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

CONF_FILES+=	${EGDIR}/sidekick.intr.ex ${PKG_SYSCONFDIR}/sidekick.intr
CONF_FILES+=	${EGDIR}/venus.conf.ex ${PKG_SYSCONFDIR}/venus.conf

post-install:
	cd ${PREFIX}; ${PAX} -zr					\
		-s "/usr\/\(man\/man.\/\)au.8/\1venus-au.8/"		\
		-s "/usr\/\(man\/man.\/\)replay.8/\1coda_replay.8/"	\
		-s "/usr\///"						\
		-f ${_DISTDIR}/${CODADOC_DISTFILE}			\
		`${GREP} "^man/" ${PLIST_SRC} |				\
			${GREP} -v "man/man8/au.8" |			\
			${SED}	-e "s|^|usr/|"				\
				-e "s|coda_replay\.8|replay.8|"		\
				-e "s|venus-au\.8|au.8|"`
	${LN} -sf venus-au.8 ${PREFIX}/man/man8/au.8

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
