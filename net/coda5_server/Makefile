# $NetBSD: Makefile,v 1.39 2003/08/30 22:51:24 jlam Exp $

PKGNAME=	coda-server-${DIST_VERS}
COMMENT=	Server programs for a replicated high-performance network file system

.include "Makefile.common"

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

CONF_FILES+=	${EGDIR}/server.conf.ex ${PKG_SYSCONFDIR}/server.conf

post-install:
	cd ${PREFIX} && ${PAX} -O -zr					\
		-s "/usr\/\(man\/man.\/\)au.8/\1vice-au.8/"		\
		-s "/usr\///"						\
		-f ${_DISTDIR}/${CODADOC_DISTFILE}			\
		`${GREP} "^man/" ${PLIST_SRC} |				\
			${SED}	-e "s|^|usr/|"				\
				-e "s|vice-au\.8|au.8|"`

.include "../../mk/bsd.pkg.mk"
