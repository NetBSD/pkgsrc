# $NetBSD: Makefile,v 1.36 2003/04/10 01:28:21 grant Exp $

PKGNAME=	coda-server-${DIST_VERS}
COMMENT=	server programs for a replicated high-performance network file system

.include "Makefile.common"

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PKGINSTALL=	yes
CONF_FILES+=	${EGDIR}/server.conf.ex ${PKG_SYSCONFDIR}/server.conf

post-install:
	cd ${PREFIX} && ${PAX} -zr					\
		-s "/usr\/\(man\/man.\/\)au.8/\1vice-au.8/"		\
		-s "/usr\///"						\
		-f ${_DISTDIR}/${CODADOC_DISTFILE}			\
		`${GREP} "^man/" ${PLIST_SRC} |				\
			${SED}	-e "s|^|usr/|"				\
				-e "s|vice-au\.8|au.8|"`

.include "../../mk/bsd.pkg.mk"
