# $NetBSD: Makefile,v 1.32 2002/06/20 19:28:35 jlam Exp $

PKGNAME=	coda-server-${DIST_VERS}
COMMENT=	server programs for a replicated high-performance network file system

USE_BUILDLINK_ONLY=	yes

.include "Makefile.common"

ALL_TARGET=		coda
INSTALL_TARGET=		server-install
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

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
