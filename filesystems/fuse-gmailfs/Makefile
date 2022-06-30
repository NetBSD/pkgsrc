# $NetBSD: Makefile,v 1.23 2022/06/30 11:18:23 nia Exp $

DISTNAME=	gmailfs-0.7.2
PKGREVISION=	6
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://richard.jones.name/google-hacks/gmail-filesystem/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://richard.jones.name/google-hacks/gmail-filesystem/gmail-filesystem.html
COMMENT=	FUSE filesystem which uses Google mail for free space

NO_BUILD=	yes
REPLACE_PYTHON=	gmailfs.py mount.gmailfs
PYTHON_VERSIONS_ACCEPTED= 27 # py-fuse-bindings

CONF_FILES=		${PREFIX}/share/examples/gmailfs/gmailfs.conf \
			${PKG_SYSCONFDIR}/gmailfs.conf

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	gmailfs.py mount.gmailfs
SUBST_VARS.config=	PKG_SYSCONFDIR
SUBST_VARS.config+=	PREFIX
SUBST_SED.config+=	-e "s|@PYSITELIB@|${PREFIX}/${PYSITELIB}|g"
SUBST_MESSAGE.config=	Fixing paths.

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

INSTALLATION_DIRS=	sbin ${PYSITELIB}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gmailfs.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/
	${INSTALL_SCRIPT} ${WRKSRC}/mount.gmailfs \
		${DESTDIR}${PREFIX}/sbin/mount_gmailfs
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gmailfs
	${INSTALL_DATA} ${WRKSRC}/gmailfs.conf \
		${DESTDIR}${PREFIX}/share/examples/gmailfs/

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
