# $NetBSD: Makefile,v 1.34 2002/09/18 21:15:14 jlam Exp $

PKGNAME=	coda-server-${DIST_VERS}
COMMENT=	server programs for a replicated high-performance network file system

.include "Makefile.common"

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

CONF_FILES+=	${EGDIR}/server.conf.ex ${PKG_SYSCONFDIR}/server.conf

post-install:
	cd ${PREFIX}; ${PAX} -zr					\
		-s "/usr\/\(man\/man.\/\)au.8/\1vice-au.8/"		\
		-s "/usr\///"						\
		-f ${_DISTDIR}/${CODADOC_DISTFILE}			\
		`${GREP} "^man/" ${PLIST_SRC} |				\
			${SED}	-e "s|^|usr/|"				\
				-e "s|vice-au\.8|au.8|"`

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
