# $NetBSD: Makefile,v 1.35 2002/09/18 21:15:13 jlam Exp $

PKGNAME=	coda-client-${DIST_VERS}
COMMENT=	client programs for a replicated high-performance network file system

.include "../../net/coda5_server/Makefile.common"

ALL_TARGET=		coda
INSTALL_TARGET=		client-install

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
